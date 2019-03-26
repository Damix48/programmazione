#include <iostream>
using namespace std;

int S(int *p, int n) {
    int n_seq = -1;
    int b = -2;
    int index = -1;
    for (int i = 0; i < 400 && p[i] != -2; i++) {
        if (p[i + 1] == -1) {
            n_seq++;
            if (n_seq == n) {
                b = index + 1;
            } else {
                index = i + 1;
            }
        }
    }
    return b;
}

int main() {
    int X[400];
    cin >> X[0];
    for (int i = 1; i < 400 && X[i - 1] != -2; i++) {
        cin >> X[i];
    }

    int n;
    cin >> n;
    cout << "start" << endl;
    int b = S(X, n); // da fare
    if (b == -2) {
        cout << "sottosequenza " << n << " non presente" << endl;
    } else {
        cout << "inizio sottosequenza " << n << " indice=" << b << endl;
    }
    cout << "end" << endl;
}
