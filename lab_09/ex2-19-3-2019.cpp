#include <iostream>
using namespace std;

void stampaS(int *A, int lim1, int lim2, int lim3, int n_ele) {
    int a = 0;

    for (int i = 0; i < lim1 && a < n_ele; i++) {
        cout << "strato" << i << endl;
        for (int j = 0; j < lim2 && a < n_ele; j++) {
            cout << "r" << j << ":";
            for (int k = 0; k < lim3 && a < n_ele; k++) {
                cout << A[i * (lim2 * lim3) + j * lim3 + k] << " ";
                a++;
            }
            cout << endl;
        }
        cout << endl;
    }
}

void stampaS2(int *A, int lim1, int lim2, int lim3, int n_ele) {
    int a = 0;

    for (int i = 0; i < lim1 && a < n_ele; i++) {
        cout << "strato" << i << endl;
        for (int j = 0; j < lim2 && a < n_ele; j++) {
            cout << "r" << j << ":";
            for (int k = 0; k < lim3 && a < n_ele; k++) {
                cout << A[i * (lim2 * lim3) + j * lim3 + k] << " ";
                a++;
            }
            cout << endl;
        }
        cout << endl;
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
    stampaS(X, lim1, lim2, lim3, n_ele);
    cout << "end" << endl;
}
