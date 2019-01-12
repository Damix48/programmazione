#include <iostream>

using namespace std;

int main() {
    // delimitatore iniziale output del programma (stringa "start")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;

    // inserire qui il codice del programma
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = (x2 - x1);
    int dy = (y2 - y1);

    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }

    if (dx == dy) {
        if (y1 > y2 && x2 > x1) {
            int dx_ = 0;
            int a = 0;
            while (dx_ < dx) {
                a = 0;
                while (a < dx_) {
                    cout << " ";
                    a++;
                }

                cout << "*" << endl;
                dx_++;
            }
        } else {
            int dx_ = dx;
            int a;
            while (dx_ > 0) {
                a = 1;
                while (a < dx_) {
                    cout << " ";
                    a++;
                }

                cout << "*" << endl;
                dx_--;
            }
        }

    } else {
        cout << "Le coordinate immesse non formano la diagonale di un quadrato" << endl;
    }

    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}