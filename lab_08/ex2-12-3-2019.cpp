#include <iostream>
using namespace std;
int main() {

    int X[2][4][5] = {}, N;
    int *x_ = &X[0][0][0];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X[(i / 5) % 2][(i / 10) % 4][i % 5];
    }

    cout << "start" << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 5; k++) {
                if (X[i][j][k] != 0) {
                    cout << X[i][j][k] << " ";
                }
            }
            if (X[i][j][0] == 0) {
            } else {
                cout << endl;
            }
        }
    }

    cout << "end" << endl;
}
