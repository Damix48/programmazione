#include <iostream>

using namespace std;

int main() {
    // delimitatore iniziale output del programma (stringa "start")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;

    // inserire qui il codice del programma
    char a, b;
    cin >> a >> b;

    if ((a == 'f' || a == 'c' || a == 's') && (b == 'f' || b == 'c' || b == 's')) {
        if (a == b) {
            cout << "pareggio" << endl;
        } else if ((a == 'f' && b == 'c') || (a == 'c' && b == 's') || (a == 's' && b == 'f')) {
            cout << "vince il giocatore 1" << endl;
        } else {
            cout << "vince il giocatore 2" << endl;
        }
    } else {
        cout << "mossa non valida" << endl;
    }

    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}