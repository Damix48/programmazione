#include <iostream>
using namespace std;

struct nodo {
    int info;
    nodo *left;
    nodo *right;

    nodo(int x = 0, nodo *l = 0, nodo *r = 0) {
        info = x;
        left = l;
        right = r;
    }
};

// FUNZIONI AUSILIARIE FORNITE
nodo *buildTree(int arr[], int i, int n) {

    if (i >= n) {
        return NULL;
    }

    nodo *root = new nodo(arr[i]);
    // insert left child
    root->left = buildTree(arr, 2 * i + 1, n);
    // insert right child
    root->right = buildTree(arr, 2 * i + 2, n);

    return root;
}

int height(nodo *root) {
    if (!root) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

void stampa_l(nodo *r) {
    if (r) {
        cout << r->info << '(';
        stampa_l(r->left);
        cout << ',';
        stampa_l(r->right);
        cout << ')';
    } else {
        cout << '_';
    }
}

void sc(int *C) {
    if (*C != -1) {
        cout << *C << ' ';
        sc(C + 1);
    } else {
        cout << "fine cammino" << endl;
    }
}
// PRE=(albero(r) è ben formato e non vuoto, k>=0 e y valore qualsiasi, C ha
// almeno tanti elementi quanta è l'altezza di albero(r))
bool cerca_cam(nodo *r, int k, int y, int *C) {
    if (r->info == y) {
        k--;
    }

    if (k == -1) {
        return false;
    }

    if (!r->left && !r->right && k == 0) {
        C[0] = -1;
        return true;
    }

    if (r->left && cerca_cam(r->left, k, y, C + 1)) {
        C[0] = 0;
        return true;
    }

    if (r->right && cerca_cam(r->right, k, y, C + 1)) {
        C[0] = 1;
        return true;
    }

    return false;
}
// POST_cerca = (restituisce true sse in albero(r) esiste un cammino da r ad una
// foglia con esattamente k nodi con campo info=y e false altrimenti) && (in
// caso restituisca true, C contiene una sequenza (anche vuota) di 0/1 seguita
// da -1 e che individua il cammino più a sinistra in albero(r) con esattamente
// k nodi con campo info=y).

/*CORRETTEZZA:

- caso base1 : y=r->info il valore di y è contenuto nella radice dell'albero e
decrementa k per segnalare che y è stato trovato

- caso base2: (k == -1) è stato trovato un alore di y in più del necessario, la
funzione ritorna false

- caso base3 :(!r->left && !r->right && k == 0) non esistono rami e root è
l'unico nodo dell'albero e sono stati trovato y k-volte, ritorna true

- caso ricorsivo 1: (r->left && cerca_cam(r->left, k, y, C + 1)) esiste un ramo
sinistro e cerca_cam ritorna true in esso, l'array C contiene nella posizione
corrente il  valore 0 se il cammino segue il ramo sinistro e la funzione ritorna
true, se il cammino non viene trovato o non termina con una foglia e
successivamente contiene altri valori=y, la funzione restituisce false

- caso ricorsivo 2: (r->right && cerca_cam(r->right, k, y, C + 1)) esiste un
ramo destro e cerca_cam ritorna true in esso, l'array C contiene nella posizione
corrente il valore 1 se il cammino segue il ramo destro e la funzione ritorna
true, se il cammino non viene trovato la o non termina con una foglia e
successivamente contiene altri valori=y, la funzione restituisce false

*/

int main() {
    int dim;
    cin >> dim;
    int *a = new int[dim];
    for (int i = 0; i < dim; i++) {
        cin >> a[i];
    }

    nodo *root = NULL;
    root = buildTree(a, 0, dim);
    int h = height(root);
    int *C = new int[h];

    int k, y;
    cin >> k >> y;
    cout << "start" << endl;
    bool b = cerca_cam(root, k, y, C);
    stampa_l(root);
    cout << endl;

    if (b) {
        cout << "trovato  cammino=";
        sc(C);
    } else {
        cout << "nessun cammino con " << k << " valori=" << y << endl;
    }
    cout << "end" << endl;
}
