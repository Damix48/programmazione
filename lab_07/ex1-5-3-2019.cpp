#include <iostream>
using namespace std;

int main() {
    int N, A[100], ind1, ind2;
    bool palindromo = true;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << "start" << endl;

    for (int i = 0; i < N / 2 && palindromo; i++) {
        if (A[i] != A[N - 1 - i]) {
            palindromo = false;
            ind1 = i;
            ind2 = N - 1 - i;
        }
    }

    if (palindromo) {
        cout << "A è un palindromo" << endl;
    } else {
        cout << "A non è un palindromo e la prima contraddizione riguarda gli "
                "elementi di indice "
             << ind1 << " e " << ind2 << endl;
    }

    cout << "end" << endl;
}
