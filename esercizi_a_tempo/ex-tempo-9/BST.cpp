#include "BST.h"
#include <iostream>
using namespace std;
// contiene le implementazioni delle 7 funzioni richieste

void stampa_l(nodo *r) {
    if (r) {
        cout << r->info;
        cout << "(";
        stampa_l(r->left);
        cout << ",";
        stampa_l(r->right);
        cout << ")";
    } else {
        cout << "_";
    }
}

nodo *insert(nodo *r, int x) {
    if (!r) {
        return new nodo(x);
    }
    if (x < r->info) {
        r->left = insert(r->left, x);
    } else {
        r->right = insert(r->right, x);
    }
    return r;
}

bool search(nodo *r, int x) {
    if (!r) {
        return false;
    }
    if (r->info == x) {
        return true;
    }
    if (x < r->info) {
        return search(r->left, x);
    } else {
        return search(r->right, x);
    }
}
nodo *max(nodo *r) {
    if (!r->right) {
        return r;
    } else {
        return max(r->right);
    }
}

// nodo *min(nodo *r) {
//     if (!r->left) {
//         return r;
//     } else {
//         return min(r->left);
//     }
// }

nodo *&min(nodo *&r) {
    if (!r->left) {
        return r;
    } else {
        return min(r->left);
    }
}

int altezza(nodo *r) {
    if (!r || (!r->left && !r->right)) {
        return 0;
    }
    int a = altezza(r->left) + 1;
    int b = altezza(r->right) + 1;

    if (a > b) {
        return a;
    }
    return b;
}

int altMin(nodo *r) {
    if (!r) {
        return 0;
    }

    int a = altezza(r->left) + 1;
    int b = altezza(r->right) + 1;

    if (a < b) {
        return a;
    }
    return b;
}

// PRE=albero(r) è ben formato e x è definito
nodo *elim1(nodo *r, int x) {
    if (r) { // caso base (1): albero(r) non è vuoto quindi va fatta
             // l'eliminazione
        if (r->info == x) {

            if (!r->left && !r->right) { // caso base (2): se r è una foglia è
                                         // corretto eliminarla e ritornare 0
                                         // => albero(r) è ben formato ed è
                                         // stato eliminato un nodo
                                         // => POST
                return 0;
            } else if (!r->left) { // caso base (2): se r non ha un figlio a
                                   // sinistra lo sostituisco con quello di
                                   // destra ritorndo r->right
                                   // => albero(r) è ben formato ed è stato
                                   // eliminato un nodo e spostato il nodo
                                   // figlio
                                   // => POST
                return r->right;
            } else if (!r->right) { // caso base (4)
                return r->left;
            } else { // caso base 5: se r ha entrambi i figli prendo il
                     // puntatore al nodo minore del suo sottoalbero destro,
                     // copio info del minimo nel campo info di r e sostituisco
                     // a minimo il suo sottoalbero destro e restituisco r
                     // modificato
                     // => albero(r) è ancora ben formato ed è stato eliminato
                     // un nodo come da testo
                     // => POST
                nodo *&y = min(r->right);
                r->info = y->info;
                y = y->right;
                return r;
            }
        } else if (x < r->info) { // PRE_ric = !(2) => albero(r) è ben formto ma
                                  // r non è il nodo da eliminare
                                  // PRE_ric verificata
            r->left = elim1(r->left, x);
            // return r;
        } else {
            r->right = elim1(r->right, x);
            // return r;
        } // POST_ric: essendo PRE_ric verificata assumo per induzione che lo
          // sia anche POST_ric
          // modifico r->left o r->right con il sottoalbero sinistro o destro
          // dove eventualmente è stato trovato un nodo da eliminare
    }
    return r;
}
