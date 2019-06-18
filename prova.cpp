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
struct coda {
    nodo *primo, *ultimo;
    coda(nodo *a = 0) {
        primo = a;
        ultimo = a;
    }
};
struct nodoE {
    coda *C;
    int N, V;
    nodoE *next;
    nodoE(coda *a = 0, int b = 0, int c = 0, nodoE *d = 0) {
        C = a;
        N = b;
        V = c;
        next = d;
    }
};

void push_end(coda *x, nodo *p) {
    p->next = 0;
    if (!x->primo)
        x->primo = x->ultimo = p;
    else {
        x->ultimo->next = p;
        x->ultimo = p;
    }
}
nodo *faiLista() {
    int x;
    cin >> x;
    if (x == -1)
        return 0;
    return new nodo(x, faiLista());
}
int conta(nodo *L) {
    if (L)
        return 1 + conta(L->next);
    return 0;
}
void stampa(nodoE *X, int n) {
    if (X) {
        if (conta(X->C->primo) == X->N && X->C->primo->info == X->V) {
            cout << "lista " << n << " con " << X->N << " nodi, con valore "
                 << X->V << endl;
            stampa(X->next, n + 1);
        } else
            cout << "errore nella lista n." << n << endl;
    }
}
// INIZIO
/*iniziofunzioni.h*/
nodoE *trova(nodoE *, int){};
void aggiungi(nodoE *, nodo *){};
nodoE *addLast(nodoE *, nodoE *){};
/*fine funzione lib.h*/
// PRE=(L è una lista benformata e ris è una lista di nodoE tali che ogni nodoE
// gestisce una lista di nodi con info uguale, Nè pari al numero dei nodi gestiti
// e V è il campo info dei nodi, Vris=ris)
nodoE *faitutto(nodo *L, nodoE *ris) {}
// POST=(restituisce ris che è ottenuta da Vris trattando ogni nodo di L nel
// modo specificato dal precedente algoritmo)

// FINE
int main() {
    cout << "start" << endl;
    nodo *K = faiLista();
    nodoE *R = faitutto(K, 0);
    stampa(R, 0);
    cout << "end" << endl;
}