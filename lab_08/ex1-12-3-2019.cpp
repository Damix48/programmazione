#include <iostream>
using namespace std;
int main() {

    int X[3][4][5];
    int *x_ = &X[0][0][0];

    for (int i = 0; i < 60; i++) {
        cin >> x_[i];
    }

    cout << "start" << endl;

    char select;
    int index;

    cin >> select;
    cin >> index;

    for (int i = 0; i < 3; i++) {
        if (select == 'H') {
            for (int j = 0; j < 5; j++) {
                cout << X[i][index][j] << " ";
            }
        } else if (select == 'V') {
            for (int j = 0; j < 4; j++) {
                cout << X[i][j][index] << " ";
            }
        }
        cout << endl;
    }

    cout << "end" << endl;
}
