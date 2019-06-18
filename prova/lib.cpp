#include "lib.h"

void push_end(coda *x, nodo *p) {
    p->next = 0;
    if (!x->primo)
        x->primo = x->ultimo = p;
    else {
        x->ultimo->next = p;
        x->ultimo = p;
    }
}

// PRE: R e' una lista ben formata e y e' un intero
nodoE *trova(nodoE *R, int y) {
    if (!R) { // Base (1)
        // R e' vuota, non contiene quindi nessun nodoE che gestisce una lista
        // che contiene nodi con campo info = y
        // Ritorno 0 => POST
        return 0;
    }

    // !(1) => R esiste
    if (R->V == y) { // Base (2)
        // R gestisce una lista di nodi con campo info = y
        // Ritorno R => POST
        return R;
    }

    // !(1) && !(2) => R non gestisce una lista con nodi con campo info = y
    // Caso ricorsivo

    // PRE_ric: !(1) => R esiste e punta ad un nodoE, per cui R->next e' una
    // lista ben formata, il resto e' garantito dalla pre di trova
    return trova(R->next, y);
    // Per ipotesi induttiva ==> POST
}
// POST: se R gestisce una lista con nodi con info = y allora la funzione
// restituisce con
//       il return l'indirizzo del nodoE che gestisce la lista di nodi con info
//       = y altrimenti restituisce con il return 0, che indica che R non
//       gestisce una lista con nodi con info=y

// PRE: X esiste e punta ad un nodoE non nullo che e' il nodoE che gestisce la
// sottolista di nodi con info = V = y->info, y esiste e punta ad un nodo non
// nullo
void aggiungi(nodoE *X, nodo *y) {
    push_end(X->C, y);
    X->N += 1;
}
// POST: X gestisce un nuovo nodo che ha info = V che e' posto in fondo alla sua
// coda, X->N = X->N + 1 poiche' ora il numero di nodi gestiti da X e' aumentato
// di 1

// PRE: R e' una lista ben formata, X e' una lista ben formata con un solo
// elemento, non nulla
nodoE *addLast(nodoE *R, nodoE *X) {
    if (!R) { // Base (1)
        // (1) => R e' una lista vuota
        return X;
        // Restituisco con il return X che e' una lista corretta (secondo la
        // PRE) e la lista contiene tutti i nodoE successivi ad R
    }

    // !(1) => R esiste e non e' vuoto
    // PRE_ric: !(1) => R e' definito, quindi R->next e' una lista ben formata,
    // il resto delle condizioni sono garantite dalla pre di addLast
    R->next = addLast(R->next, X);
    return R;
}
// POST: Restiruisce con il return una lista corretta che contiene tutti i nodoE
// successivi ad R

// PRE: L e' una lista ben formata e ris e' una lista di nodoE tali che ogni
// nodoE gestisce una lista di nodi con info uguale, N e' pari al numero di nodi
// gestiti e V e' il campo info dei nodi, Vris=ris
nodoE *faitutto(nodo *L, nodoE *ris) {
    if (!L) { // Base (1)
        // (1) => L non contiene piu' elementi
        return ris;
        // Restituisco ris => POST
    }

    // !(1) => L ha ancora elementi
    // Cerco se ci sono in ris liste che gestiscono nodi con info = L->ris
    nodoE *R = trova(ris, L->info);

    if (!R) { // Non esiste nessun nodoE che gestisce
              // i nodi con campo info = L->info

        // Creo una nuova coda che conterra' tutti i nodi con info = L->info
        coda *C = new coda();
        // Creo un nuovo nodoE che gestira' i nodi con info = L->info e che
        // conterra' la coda appena creata
        R = new nodoE(C, 0, L->info);
        // Aggiungo il nuovo nodoE appena creato a ris
        ris = addLast(ris, R);
    }

    // Salvo il nodo successivo ad L poiche' quando lo aggiungo alla sottolista
    // che lo gestisce, questo viene scollegato dalla lista originale
    nodo *oldNext = L->next;
    // Aggiungo il nodo alla sottolista che lo gestisce
    aggiungi(R, L);

    // PRE_ric: !(1) => L e' definito, quindi L->next e' una lista ben definita,
    // ris e' una lista di nodoE ==> PRE
    return faitutto(oldNext, ris);
    // Per ipotesi induttiva e' valida anche la POST_ric
    // Restituisco con il return il valore ritornato da faitutto(), l'unico caso
    // base e' (1) in cui faitutto() restituisce ris e la POST e' soddisfatta =>
    // POST soddisfatta
}
// POST: restituisce ris che e' ottenuta da Vris trattando ogni nodo di L nel
// modo specificato dal precedente algoritmo