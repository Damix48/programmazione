#include <iostream>

using namespace std;

int main() {
    // delimitatore iniziale output del programma (stringa "start")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;

    // inserire qui il codice del programma
    int n;
    cin >> n;
    if (n >= 3) {
        int a = 0;
        while (a < (n - 2)) {
            cout << " ";
            a++;
        }
        cout << "*" << endl;

        int n_ = 0;
        while (n_ < n - 1) {
            a = 0;
            while (a < n_) {
                cout << " ";
                a++;
            }
            a = 0;
            while (a < (n - n_) * 2 - 3) {
                cout << "*";
                a++;
            }

            cout << endl;
            n_++;
        }

    } else {
        cout << "Altezza non valida" << endl;
    }

    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}