#include <iostream>

using namespace std;

int main() {
    // delimitatore iniziale output del programma (stringa "start")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;

    // inserire qui il codice del programma
    char a = ' ';
    int p_c = 0;
    int p_a = 0;
    while (a != '0') {
        cin >> a;
        if (a == '(') {
            p_a++;
        } else if (a == ')') {
            p_c++;
        }
        if (p_c > p_a) {
            a = '0';
            cout << "la sequenza non e' bilanciata: ci sono parentesi chiuse senza match" << endl;
        }
    }
    if (p_c == p_a) {
        cout << "la sequenza e' bilanciata" << endl;
    } else if (p_a > p_c) {
        cout << "la sequenza non e' bilanciata: ci sono parentesi aperte senza match" << endl;
    }

    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}