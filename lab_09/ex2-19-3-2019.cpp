#include <iostream>
using namespace std;

void stampaS(int *A, int lim1, int lim2, int lim3, int n_ele) {
    int fette_piene = n_ele / (lim2 * lim3);
    int ultima_riga = n_ele % lim3;
    int e3;
    int e4;

    for (int i = 0; i < fette_piene + 1 && i < lim1; i++) {
        if (i == fette_piene && (fette_piene * i * lim2 * lim3 < n_ele)) {

        } else {
            for (int j = 0; j < e4; j++) {
                for (int k = 0; k < e3; k++) {
                    cout << A[i * (lim2 * lim3) + j * lim3 + k];
                }
            }
        }
    }
}

int main() {
    int n_ele, lim1, lim2, lim3, X[400];
    cin >> n_ele;

    for (int i = 0; i < n_ele; i = i + 1) {
        cin >> X[i];
    }
    cin >> lim1 >> lim2 >> lim3;

    cout << "start" << endl;

    cout << "end" << endl;
}
