#include <iostream>

using namespace std;

int main() {
    // delimitatore iniziale output del programma (stringa "start")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;

    // inserire qui il codice del programma
    int a, b, c;
    cin >> a >> b >> c;

    if (a <= b && a <= c) {
        cout << "il minimo e': " << a << endl;
    } else if (b <= a && b <= c) {
        cout << "il minimo e': " << b << endl;
    } else if (c <= a && c <= b) {
        cout << "il minimo e': " << c << endl;
    }

    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}