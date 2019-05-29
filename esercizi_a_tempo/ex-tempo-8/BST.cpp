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
    if (!r || (!r->left && !r->right)) {
        return 0;
    }

    int a = altMin(r->left) + 1;
    int b = altMin(r->right) + 1;

    if (a < b) {
        return a;
    }
    return b;
}

void elim(nodo *&r, int x) {
    if (r != NULL) // Caso base (1)
    {
        if (r->info == x) // Caso base (2)
        {
            if (r->left == NULL && r->right == NULL)
                r = NULL;
            else if (r->right == NULL)
                r = r->left;
            else if (r->left == NULL)
                r = r->right;
            else {
                nodo *&y = min(r->right);
                nodo *p = y;
                y = y->right;
                p->right = r->right;
                p->left = r->left;
                r->right = NULL;
                r->left = NULL;
                r = p;
                // delete r;
            }
        } else if (x < r->info) // Caso ricorsivo (1)
        {
            elim(r->left, x);
        } else // if(x > r->info) Caso ricorsivo (2)
        {
            elim(r->right, x);
        }
    }
}