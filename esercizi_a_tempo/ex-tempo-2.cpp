#include <iostream>
using namespace std;

bool patternCheck(int *A, int dim, int *Pattern, int dim_p) {
    bool trovato = false;

    // PRE: A contiene dim elementi; Pattern contiene dim_p elementi;
    // trovato=false

    for (int i = 0; i < dim && !trovato; i++) {
        // R1: (0<=i<=dim) && trovato==false SSE non sono stati trovati match
        // tra A[i..(i+dim)] e Pattern[0..dim]

        bool controllo = false;
        for (int j = 0; j < dim_p && !controllo; j++) {
            // R2: (0<=i<=dim) && controllo==false SSE sono state trovate j
            // corrispondenze tra A[i+j] e Pattern[j]

            if (A[i + j] != Pattern[j] || (i + j) >= dim) {
                controllo = true;
            } else if (A[i + j] == Pattern[j] && j + 1 == dim_p) {
                trovato = true;
            }
        }
    }

    // POST: trovato=true SSE è stato trovato un matching tra A[i..(i+dim)] e
    // Pattern[0..dim]

    return trovato;
}

int main() {
    int X[400], n_ele, nP, P[20];
    int lim1, lim2, lim3;

    cin >> n_ele;

    for (int i = 0; i < n_ele; i++) {
        cin >> X[i];
    }

    cin >> lim1 >> lim2 >> lim3;
    cin >> nP;

    for (int i = 0; i < nP; i++) {
        cin >> P[i];
    }

    cout << "start" << endl;

    int dim_strato = lim2 * lim3;
    int piene = n_ele / dim_strato;
    int ele_ultimi = n_ele % dim_strato;

    bool trovato = false;
    int index = 0;

    // PRE: X contiene n_ele elementi; P contiene nP elementi trovato=false;
    // index=0;

    for (int i = 0; i < lim1 && !trovato; i++) { // ciclo_1
        // R0: (0<=i<=lim1) && trovato==false SSE non sono stati trovati
        // matching nell'i-esimo strato

        int dim = dim_strato;

        if (i == piene && ele_ultimi > 0) {
            dim = ele_ultimi;
        }

        trovato = patternCheck(X + (dim_strato * i), dim, P, nP);
        if (trovato) {
            index = i;
        }
    }

    // POST: trovato=true SSE è stato trovato un match in A con il pattern P;
    // index contiene l'indice del primo strato in cui c'è un matching

    if (trovato) {
        cout << "lo strato " << index << " di T contiene un match" << endl;
    } else {
        cout << "Nessun match trovato" << endl;
    }

    cout << "end" << endl;
}

/* PROVA di CORRETTEZZA di ciclo_1 nel main

- CONDIZIONE INIZIALE (PRE => R0):
    R0 vale la prima volta dato che con i=0 e trovato=false, R diventa
    0<=0<=lim1 => OK false==false => OK (non sono stati trovati match)

- INVARIANZA (R0 && B <corpo> => R0):
    R0 && (i < lim1 && !trovato) => è stato controllato l'i-esimo strato e si
    deve eseguire il corpo che controlla che l'(i+1)-esimo strato abbia un
    matching con il pattern P, se c'è il mathing trovato=true e in qualsiasi
    caso aumenta i di 1. => Vale R0

- TERMINAZIONE (R0 && !B => R0):
    R0 && !(i < lim1 && !trovato) => R0 && (i == lim1 || trovato) => sono stati
    controllati lim1 strati oppure sono stati controllati (index+1) strati
    perchè è stato trovato un matching nell'index-esimo strato

*/