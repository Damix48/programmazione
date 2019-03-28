#include <iostream>
using namespace std;

int S(int *p, int n) {
    int n_seq = -1;
    int b = -2;
    int index = -1;
    for (int i = 0; i < 400 && p[i] != -2; i++) {
        if (p[i + 1] == -1) {
            n_seq++;
            if (n_seq == n) {
                b = index + 1;
            } else {
                index = i + 1;
            }
        }
    }
    return b;
}

int S2(int *p, int n) { // tutorato
    int s = 0;
    int j = 0;

    // PRE: p è un array valido di zero o più sequanze che finiscono con -1 che
    // finisce con -2 && n>=0 && s==j==0
    while (s < n && p[j] != 2) {
        // R: 0<=j && s è il numero di -1 in p[0..j-1]

        if (p[j] == -1) {
            s++;
        }
        j++;
    }
    // POST: p[j]==-2 => non esiste la sottosequenza n-esima && p[j]!=-2 => j è
    // l'indice del primo elemento della n-esima sottosequenza

    if (p[j] != -2) {
        return j;
    } else {
        return -2;
    }
}

/* PROVA di CORRETTEZZA

- CONDIZIONE INIZIALE (PRE => R):
    j==0 => j>=0 && (s==0 && p[0..j-1] è vuoto) => s è il numero di -1 in
    p[0..j-1]

- INVARIANZA (R && B <corpo> => R):
    j>=0 && j viene incrementato => j>=0; s è il numero di -1 in p[0..j-1] => s
    è incrementato && j viene incrementato => R

- TERMINAZIONE (R && !B => R):
    

*/

int main() {
    int X[400];
    cin >> X[0];
    for (int i = 1; i < 400 && X[i - 1] != -2; i++) {
        cin >> X[i];
    }

    int n;
    cin >> n;
    cout << "start" << endl;
    int b = S2(X, n); // da fare
    if (b == -2) {
        cout << "sottosequenza " << n << " non presente" << endl;
    } else {
        cout << "inizio sottosequenza " << n << " indice=" << b << endl;
    }
    cout << "end" << endl;
}
