#include <iostream>
using namespace std;

int match(int *A, int lim3, int dim, int *Pattern, int dim_p) {
    int trovato = -1;

    // PRE: A contiene dim elementi; Pattern contiene dim_p elementi; trovato=-1

    for (int i = 0; i < (dim - dim_p + 1) && trovato == -1; i++) {
        // R1: (0<=i<=(dim - dim_p + 1)) && trovato==-1 SSE non sono stati
        // trovati match tra A[i..(i+dim-1)] e Pattern[0..dim_p-1]

        bool controllo = false;

        for (int j = 0; j < dim_p && !controllo; j++) {
            // R2: (0<=i<=dim) && controllo==false SSE sono state trovate j
            // corrispondenze tra A[(i + j) * lim3] e Pattern[j]

            if (A[(i + j) * lim3] != Pattern[j]) {
                controllo = true;
            } else if (A[(i + j) * lim3] == Pattern[j] && j + 1 == dim_p) {
                trovato = i;
            }
        }
    }

    // POST: trovato=indice di inizio del pattern sulla colonna SSE è stato
    // trovato un match in A[0..(dim-1)] con il Pattern[0..(dim_p-1)]

    return trovato;
}

/* PROVA di CORRETTEZZA della funzione `match`

- CONDIZIONE INIZIALE (PRE => R1):
    R1 vale la prima volta dato che con i=0 e trovato=-1, R diventa 0<=0<=(dim -
    dim_p + 1) che è OK e -1==-1 che è OK (quindi non sono stati trovati match)

- INVARIANZA (R1 && B <corpo> => R1):
    R1 && (i < (dim - dim_p + 1) && trovato == -1) => è stato controllato il
    match a partire dall'i-esimo elemento della V-fetta fino all'(i+dim_p)-esimo
    elemento della V-fetta con il pattern Pattern ed controllo=-1 SSE non sono
    state trovate corrispondenze, altrimenti controllo=i

- TERMINAZIONE (R1 && !B => POST):
    R1 && !(i < (dim - dim_p + 1) && trovato == -1) => R1 && (i >= (dim - dim_p
    + 1) || trovato != -1) => sono state controllate le corrispondenze tra
    A[0..dim-1] e Pattern[0..dim_p-1] e trovato è stato impostato a i se è stato
    trovato un match

*/

int main() {
    int X[400], P[20], n_ele, nP, lim1, lim2, lim3;

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

    int dim_v_fetta = n_ele / lim3;
    int n_v_fette_grandi = n_ele % lim3;

    int trovato = -1;
    int index = 0;

    for (int i = 0; i < lim3 && trovato == -1; i++) {

        int dim = dim_v_fetta;

        if (i < n_v_fette_grandi) {
            dim++;
        }

        if (n_ele > lim1 * lim2 * lim3) {
            dim = lim1 * lim2;
        }

        trovato = match((X + i), lim3, dim, P, nP);
        if (trovato != -1) {
            index = i;
        }
    }

    if (trovato != -1) {
        cout << "La V-fetta " << index
             << " contiene un match che inizia nell'elemento " << trovato
             << endl;
    } else {
        cout << "Nessun match trovato" << endl;
    }

    cout << "end" << endl;
}
