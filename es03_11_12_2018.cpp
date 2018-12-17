#include <iostream>

using namespace std;

int main() {
    // delimitatore iniziale output del programma (stringa "start")\
	// ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;

    // inserire qui il codice del programma
    int a, b, c;
    cin >> a >> b >> c;
    if (a > 0 && b > 0 && c > 0) {
        if (b + c > a && a + c >> b && a + b > c) {
            cout << "Si" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "Input sbagliato" << endl;
    }

    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}