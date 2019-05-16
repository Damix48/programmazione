#include <iostream>
using namespace std;

// PRE_t: (N ha almeno m*m elementi definiti, 0<=i<m, j è definito e P ha m-i
// posizioni)
bool trova(bool *N, int m, int i, int j, int *P) {
    if (i == m) {
        return true;
    }
    if (j >= m || j < 0) {
        return false;
    }
    if (!N[i * m + j]) {
        return false;
    } else {
        P[i] = j;
        return (trova(N, m, i + 1, j - 1, P) || trova(N, m, i + 1, j, P) ||
                trova(N, m, i + 1, j + 1, P));
    }
}
// POST_t: (restituisce true sse in N vista come X[m][m] c’è un cammino dalla
// casella (i,j) alla riga m-1 composto da sole caselle bianche) &&(se la
// risposta è true, in P [0..m-i-1] c’è il cammino più a sinistra con queste
// proprietà)

/*   CORRETTEZZA   */
//
// - caso base (i == m): sono stati controllati tutti i possibili percorsi e in
// P[0..m-1] c'è quello più a sinistra, la funzione quindi restiuisce
// correttamente true => POST_t OK
//
// - caso base (j >= m || j < 0): la funzione cerca di controllare valori che
// non appartengono all'array, restiuisce quindi false => POST_t OK
//
// - caso base (!N[i * m + j]): la funzione controlla il valore dell'elemento in
// N e dato che risulta falso (proibito) restituisce falso => POST_t OK
//
// - caso ricorsivo:
// /*
// else {
//     P[i] = j;

//     PRE_ric: 0<=i+1<=m => PRE_t OK
//     return (trova(N, m, i + 1, j - 1, P) || trova(N, m, i + 1, j, P) ||
//             trova(N, m, i + 1, j + 1, P));
//     POST_ric: restituisce true sse in N vista come X[m][m] c'è un cammino
//     dalla casella (i+1, j-1) oppure dalla casella (i+1, j) oppure dalla
//     casella (i+1, j+1) alla riga m-1 composto solo da caselle bianche
//     a) N[i * m + j] == true e una delle sequenze che iniziano con le caselle
//     (i+1, j-1) o (i+1, j) o (i+1, j+1) raggiunge la riga m-1 con caselle
//     bianche
//     b) N[i * m + j] == true e tutte le sequenze che iniziano con le caselle
//     (i+1, j-1) o (i+1, j) o (i+1, j+1) non raggiungono la riga m-1 con
//     caselle bianche
//
//     In entrambi i casi, a) o b) => POST_t OK
// }
// */

// PRE_p=(N ha m*m valori definiti, 0<=i<=m e P ha m elementi)
bool partenza(bool *N, int m, int i, int *P) {
    bool t = trova(N, m, 0, i, P);

    if (t) {
        return true;
    } else if (i == m - 1 && !t) {
        return false;
    } else {
        return partenza(N, m, i + 1, P);
    }
}
// POST_p: (risponde true sse esiste un cammino di caselle bianche dalla prima
// all’ultima riga di N, vista come X[m][m], e che inizia in una casella tra i e
// m-1 della prima riga di X) && (se risponde true allora P[0..m-1] è il cammino
// più a sinistra con queste proprietà)

void stampa(int *P, int m, int i) {
    if (i == m) {
        cout << endl;
        return;
    }
    cout << '(' << i << ',' << P[i] << ')' << ' ';
    stampa(P, m, i + 1);
}

int main() {
    int m;
    cin >> m;
    int *P = new int[m];
    bool *N = new bool[m * m];
    for (int i = 0; i < m * m; i++) {
        cin >> N[i];
    }
    bool x = partenza(N, m, 0, P); // da fare
    cout << "start" << endl;
    if (x) {
        cout << "esiste un cammino e quello più a sinistra è:" << endl;
        stampa(P, m, 0);
    } else {
        cout << "il cammino non esiste" << endl;
    }
    cout << "end" << endl;
}
