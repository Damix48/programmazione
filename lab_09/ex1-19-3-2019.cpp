#include <iostream>
using namespace std;

int colonna(int *A, int n, int step) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma = somma + A[i * step];
    }
    return somma;
}

// PRE=(cin contiene n_ele, 0<n_ele<=400, seguito da n_ele interi qualsiasi)
int main() {
    int A[10][5][10], *p = A[0][0];
    int n_ele, bestfetta, bestvalue = 0;
    cin >> n_ele;
    for (int i = 0; i < n_ele; i++) {
        cin >> p[i];
    }

    int n_colonne;

    if (n_ele > 8) {
        n_colonne = 8;
    } else {
        n_colonne = n_ele;
    }

    for (int i = 0; i < n_colonne; i++) {

        int n = n_ele / 8;
        if (i < n_ele % 8) {
            n++;
        }

        int temp = colonna(p, n, 8);
        if (i == 0) {
            bestvalue = temp;
            bestfetta = i;
        }
        if (temp >= bestvalue) {
            bestvalue = temp;
            bestfetta = i;
        }

        p++;
    }

    cout << "start" << endl;
    // da fare
    cout << "V-fetta massima= " << bestfetta << " con somma= " << bestvalue
         << endl;
    cout << "end" << endl;
}
// POST=(stampa l'indice della V-fetta a somma massima seguito dalla sua somma e
// in caso di parità, stampa l'indice massimo)

int colonna(int *A, int n, int step) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma = somma + A[i * step];
    }
    return somma;
}