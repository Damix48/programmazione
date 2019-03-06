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
        int n_ = n;
        while (n_ > 1) {
            int a = 0;
            while (a < (n_ - 2)) {
                cout << " ";
                a++;
            }
            a = 0;
            while (a < (n - n_) * 2 + 1) {
                cout << "*";
                a++;
            }

            cout << endl;
            n_--;
        }
        int a = 0;
        while (a < (n - 2)) {
            cout << " ";
            a++;
        }
        cout << "*" << endl;
    } else {
        cout << "Altezza non valida" << endl;
    }

    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}