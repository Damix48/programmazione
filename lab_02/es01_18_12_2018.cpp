#include <iostream>

using namespace std;

int main() {
    // delimitatore iniziale output del programma (stringa "start")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;

    // inserire qui il codice del programma
    int n;
    int count = 0;
    int v_a = 0;
    int v_b = 0;
    cin >> n;
    while (count < n) {
        char a, b;
        cin >> a >> b;
        if ((a == 'f' || a == 'c' || a == 's') && (b == 'f' || b == 'c' || b == 's')) {
            if (a == b) {
                v_a++;
                v_b++;
                count++;
            } else if ((a == 'f' && b == 'c') || (a == 'c' && b == 's') || (a == 's' && b == 'f')) {
                v_a++;
                count++;
            } else {
                v_b++;
                count++;
            }
        }
    }
    if (v_a == v_b) {
        cout << "Pareggio" << endl;
    } else if (v_a > v_b) {
        cout << "Vince il Giocatore 1" << endl;
    } else {
        cout << "Vince il Giocatore 2" << endl;
    }
    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}