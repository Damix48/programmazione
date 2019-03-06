#include <iostream>
using namespace std;

int main() {
    int N, A[100];
    int val[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << "start" << endl;

    for (int i = 0; i < N; i++) {
        val[A[i]]++;
    }
    int maxx = 0;
    for (int i = 0; i < 10; i++) {
        if (val[i] > maxx) {
            maxx = val[i];
        }
    }
    for (int i = 0; i < maxx; i++) {
        for (int j = 0; j < 10; j++) {
            if (val[j] >= maxx - i) {
                cout << "*";
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
    cout << "0123456789" << endl;

    cout << "end" << endl;
}