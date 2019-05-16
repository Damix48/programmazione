#include <iostream>

using namespace std;

bool controlloLetture(int n_letture) { return n_letture == 3; }

bool controlloTempi(int **indirizzi) {
    bool t = true;

    for (int i = 0; i < 2 && t; i++) {
        // cout << *(indirizzi[i] + 2) << endl;
        if (*(indirizzi[i] + 0) == i) {
            for (int j = 0; j < 3 && t; j++) {
                if (*(indirizzi[j] + 0) == i + 1) {
                    int ore1 = *(indirizzi[i] + 2) * 3600;
                    int minuti1 = *(indirizzi[i] + 3) * 60;
                    int secondi1 = *(indirizzi[i] + 4);
                    int ore2 = *(indirizzi[j] + 2) * 3600;
                    int minuti2 = *(indirizzi[j] + 3) * 60;
                    int secondi2 = *(indirizzi[j] + 4);
                    int km = 11;
                    int deltaT = (ore2 + minuti2 + secondi2) -
                                 (ore1 + minuti1 + secondi1);
                    t = deltaT / km > 2 * 60 + 45;
                }
            }
        }
    }
    return t;
}

bool controlloPartecipante(int partecipante, int **indirizzi, int n_letture) {
    bool t, t2 = false;

    t = controlloLetture(n_letture);
    if (!t) {
        cout << partecipante << ": salto sensore" << endl;
    } else {
        t2 = controlloTempi(indirizzi);
        if (!t2) {
            cout << partecipante << ": tempo sospetto" << endl;
        }
    }
    return t && t2;
}

int main() {
    int n_part, HH, MM, SS;

    cin >> n_part;
    cin >> HH;
    cin >> MM;
    cin >> SS;

    int letture[n_part * 3][5];

    int n_letture = 0;
    bool finito = false;

    while (!finito) {
        for (int i = 0; i < 5; i++) {
            int temp;
            cin >> temp;
            if (temp == -1) {
                finito = true;
            } else {
                letture[n_letture][i] = temp;
            }
        }
        n_letture++;
    }

    n_letture--;

    cout << "start" << endl;

    // stampa(letture, n_letture);

    int garaPulita = true;
    for (int i = 0; i < n_part; i++) {
        int *indirizzi[3];

        int index = 0;
        for (int j = 0; j < n_letture; j++) {

            if (letture[j][1] == i) {
                indirizzi[index] = letture[j];
                index++;
            }
        }
        bool temp = controlloPartecipante(i, indirizzi, index);
        if (garaPulita) {
            garaPulita = temp;
        }
    }

    if (garaPulita) {
        cout << "gara regolare" << endl;
    }

    cout << "end" << endl;
}
