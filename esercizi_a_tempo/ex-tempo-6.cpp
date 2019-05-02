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

struct nodoP {
    nodo *P;
    nodoP *next;
    nodoP(nodo *a = 0, nodoP *b = 0) {
        P = a;
        next = b;
    }
};

// PRE=(cin contiene n valori sequiti da -1 con n>=0)
nodo *leggi() {
    int temp;
    cin >> temp;
    if (temp == -1) {
        return 0;
    }
    return new nodo(temp, leggi());
}
// POST=(restituisce una lista concatenata con n nodi tale che il campo info del
// nodo 0 sia x0, quello del nodo 1 sia x1, e così via)

void stampa(nodoP *temp) {
    if (temp) {
        cout << temp->P->info << " ";
        stampa(temp->next);
    }
}

// PRE=(Lista(L) è ben formata, x è definito)
nodoP *aux(nodo *L, int x) {
    if (!L) {
        return 0;
    }
    if (L->info != x) {
        return aux(L->next, x); //(a)
    }
    return new nodoP(L, aux(L->next, x)); //(b)
}
// POST=(restituisce una lista di nodoP lunga come il n. di nodi di Lista(L)
// con x=info e i cui nodi puntano a questi nodi di L nell’ordine in cui i
// nodi sono in L)

/*   CORRETTEZZA   */

// - caso base (!L): non esiste il nodo L nella lista Lista(L), la funzione
// restituisce quindi 0.

// - caso ricorsivo: L->info==x trova un match nel primo nodo di L e creo un
// nodo che punta ad L tramite il campo info della lista creata sulla base di
// nodoP
// aux(L->next, x) sia in (a) e in (b) invoca la chiamata ricorsiva per
// controllare eventuali match di x con altri nodi della lista L

//       PRE_ric: Lista(L) è ben formata && x è definito; è vero, e quindi vale
//       la POST_ric cioè dopo

//               if (L->info != x) {
//                       return aux(L->next, x);
//               }
//               return new nodoP(L, aux(L->next,x));

//       la funzione ha restituito una lista di nodoP lunga come il numero di
//       nodi di Lista(L) con info==x e i cui nodi puntano a questi nodi fi L
//       nell'ordine in cui i nodi sono in L.

nodoP *ultimo(nodoP *y) {
    if (!y->next) {
        return y;
    }
    return ultimo(y->next);
}

nodoP *F(nodo *L) {
    int temp;
    cin >> temp;
    if (temp == -1) {
        return 0;
    }

    nodoP *y = aux(L, temp);
    // nodoP *y = ultimo(aux(L, temp));
    // stampa(y);
    if (!y) {
        return F(L);
    } else {
        ultimo(y)->next = F(L);
    }

    return y;
}

int main() {
    cout << "start" << endl;
    nodo *L = leggi();
    nodoP *y = F(L);
    stampa(y);
    cout << endl;
    cout << "end" << endl;
}
