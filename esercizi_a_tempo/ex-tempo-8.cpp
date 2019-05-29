#include <iostream>
using namespace std;
struct nodo {
    int info;
    nodo *next;
    nodo(int a = 0, nodo *b = 0) {
        info = a;
        next = b;
    }
};
// funzioni per input e output
nodo *buildL(int k) {
    if (!k)
        return 0;
    else {
        int x;
        cin >> x;
        return new nodo(x, buildL(k - 1));
    }
}
void leggiA(int *A, int k) {
    for (int i = 0; i < k; i++)
        cin >> A[i];
}
nodo *clone(nodo *L) {
    if (!L)
        return 0;
    else
        return new nodo(L->info, clone(L->next));
}
void stampa(nodo *L) {
    if (!L)
        cout << endl;
    else {
        cout << L->info << ' ';
        stampa(L->next);
    }
}

nodo *aux(nodo *&L, int n) {
    if (!L)
        return 0;
    if (n == 0) {
        nodo *tmp = L;
        L = 0;
        return tmp;
    }
    return aux(L->next, n - 1);
}

nodo *getLast(nodo *L) { return (L->next) ? getLast(L->next) : L; }

void Fric(nodo *L, int *A, int dimA, nodo *&L1, nodo *&L2) {
    if (!L)
        return;
    if (dimA == 0) {
        if (!L1)
            L1 = L;
        else {
            nodo *last = getLast(L1);
            last->next = L;
        }
        return;
    }
    if (dimA % 2 == 0) {
        if (*A > 0) {
            if (!L1)
                L1 = L;
            else {
                nodo *last = getLast(L1);
                last->next = L;
            }
            L = aux(L, *A);
        }
        Fric(L, A + 1, dimA - 1, L1, L2);
    } else {
        if (*A > 0) {
            if (!L2)
                L2 = L;
            else {
                nodo *last = getLast(L2);
                last->next = L;
            }
            L = aux(L, *A);
        }
        Fric(L, A + 1, dimA - 1, L1, L2);
    }
}

int main() {
    cout << "start" << endl;
    int n, dimA;
    cin >> n >> dimA;
    int *A = new int[dimA];
    nodo *L = buildL(n);
    leggiA(A, dimA);
    stampa(L);

    nodo *L1 = 0, *L2 = 0;
    Fric(L, A, dimA, L1, L2);
    stampa(L1);
    stampa(L2);

    cout << "end" << endl;
    return 0;
}