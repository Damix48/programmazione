#include <iostream>
using namespace std;

int main() {
    int A1[10][5];
    int A2[10][5];
    int *y1 = &A1[0][0];
    int *y2 = &A2[0][0];

    bool B[10][10];

    for (int i = 0; i < 50; i++) {
        int n = i;
        cin >> n;
        y1[i] = n;
        y2[(i * 5) % 50 + i / 10] = n;
    }

    cout << "start" << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            cout << A1[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            cout << A2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bool trovato = false;
            int k = 0;
            while (k < 5 && !trovato) {
                int w = 0;
                while (w < 5 && !trovato) {
                    trovato = A2[i][k] == A2[j][w];
                    w++;
                }
                k++;
                B[i][j] = !trovato;
            }
        }
    }

    cout << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "end";
}