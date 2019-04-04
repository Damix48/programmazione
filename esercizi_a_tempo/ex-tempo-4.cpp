#include <iostream>

#include <iostream>
using namespace std;

int F(int i, int lim2, int lim3) {
    return ((i / lim3) * (lim2 * lim3) + i % lim3);
}

// PRE:(T punta all’inizio di una H-fetta in X tale che a partire dal suo
// elemento inizio abbia almeno nP elementi, P, nP, lim2 e lim3, sono
// definiti ed hanno il senso usuale)

bool match(int *T, int inizio, int *P, int nP, int lim2, int lim3) {
    bool controllo = true;
    int d;
    for (int i = 0; i < nP && controllo; i++) {
        // R1: (0<=i<=nP) && controllo==true SSE sono state trovate i
        // corrispondenze tra T[F(inizio + i, lim2, lim3)] e P[i]

        if (P[i] != T[F(inizio + i, lim2, lim3)]) {
            controllo = false;
        }
    }
    return controllo;
}

// POST: (restituisce true sse nella H-fetta che inizia in T, gli elementi,
// inizio, inizio+1,..inizio+nP-1 sono identici a P[0..nP-1])

/* PROVA di CORRETTEZZA della funzione `match`

- CONDIZIONE INIZIALE (PRE => R1):
    R1 vale la prima volta dato che con i=0 e controllo=true, R diventa
    0<=0<=nP che è OK && true che è OK (quindi non sono stati trovati match)

- INVARIANZA (R1 && B <corpo> => R1):
    R1 && (i < nP && controllo) => è stato controllato il match tra l'(inizio +
    i)-esimo elemento dell'H-fetta e l'i-esimo elemento del Pattern (P) e
    controllo resta true SSE è stata trovata la corrispondeza, in caso contrario
    controllo=false

- TERMINAZIONE (R1 && !B => POST):
    R1 && !(i < nP && controllo) => R1 && (i >= nP || controllo==false) => sono
    state controllate le corripondenze tra gli nP elementi a partire da `inizio`
    della H-fetta e gli nP elementi del Pattern e sono risultate tutte vere e
    quindi la funzione restituisce true, oppure non è stata trovata una
    corrispondenza e la funzione restituisce false

*/

int main() {
    int X[400], P[20], n_ele, nP, lim1, lim2, lim3;

    cin >> n_ele;
    for (int i = 0; i < n_ele; i++) {
        cin >> X[i];
    }

    cin >> lim1 >> lim2 >> lim3;
    if (lim1 * lim2 * lim3 < n_ele) {
        n_ele = lim1 * lim2 * lim3;
    }

    cin >> nP;
    for (int i = 0; i < nP; i++) {
        cin >> P[i];
    }

    int nsp = n_ele / (lim2 * lim3), eus = n_ele % (lim2 * lim3),
        rpus = eus / lim3, ur = eus % lim3;

    cout << "start" << endl;

    bool trovato = false;
    for (int i = 0; i < lim2 && !trovato; i++) {
        int dimensione = nsp * lim3;

        if (i < rpus) {
            dimensione = dimensione + lim3;
        } else if (i == rpus) {
            dimensione = dimensione + ur;
        }

        for (int j = 0; j < dimensione - nP + 1 && !trovato; j++) {
            trovato = match(X + i * lim3, j, P, nP, lim2, lim3);
            if (trovato) {
                cout << "match trovato a partire dalla posizione " << j
                     << " della H-fetta " << i << endl;
            }
        }
    }

    if (!trovato) {
        cout << "nessun match trovato" << endl;
    }

    cout << "end" << endl;
}
