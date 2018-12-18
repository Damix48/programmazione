#include <iostream>

using namespace std;

int main() {
    // delimitatore iniziale output del programma (stringa "start")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;

    // inserire qui il codice del programma
    char a = ' ';
    bool ciclo = true;
    int count = 0;
    int p_c = 0;
    int p_a = 0;
    int parola = 0;
    while (ciclo) {
        cin >> a;
        if (a == '(') {
            p_a++;
            parola = 0;
        } else if (a == ')') {
            p_c++;
            parola = 0;
        } else if (a == 'e') {
            parola++;
        } else if (a == 'n' && parola == 1) {
            parola++;
        } else if (a == 'd' && parola == 2) {
            ciclo = false;
        }
        if (p_c > p_a) {
            ciclo = false;
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