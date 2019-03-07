#include <iostream>
using namespace std;

int main() {
    int A1[10][5];
    int A2[10][5];
    int *y1 = &A1[0][0];
    int *y2 = &A2[0][0];

    bool B[10][10];

    for (int i = 0; i < 50; i++) {
        // R1: (0<=i<=50) && (sono stati letti `i` valori)

        int n = i;
        cin >> n;
        y1[i] = n;
        y2[(i * 5) % 50 + i / 10] = n;
    }

    cout << "start" << endl;

    for (int i = 0; i < 10; i++) {
        // R2: (0<=i<=10) && (sono stati stampati i*j valori)

        for (int j = 0; j < 5; j++) {
            // R3: (0<=i<=5) && (sono stati stampati j valori)

            cout << A1[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        // R4: (0<=i<=10) && (sono stati stampati i*j valori)

        for (int j = 0; j < 5; j++) {
            // R5: (0<=i<=5) && (sono stati stampati j valori)

            cout << A2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        // R6: (0<=i<=10) && (sono stati scritti i*j valori in
        // B[0][0]...B[i][j])

        for (int j = 0; j < 10; j++) {
            // R7: (0<=i<=10) && (sono stati scritti j valori in
            // B[i][0]...B[i][j])

            bool trovato = false;
            int k = 0;

            while (k < 5 && !trovato) {
                // R8: (0<=k<=5) && (controllate k*w uguaglianze tra
                // A2[i][0...k] e A2[j][0...w] && !trovato sse non trovati
                // duplicati)

                int w = 0;
                while (w < 5 && !trovato) {
                    // R9: (0<=w<=5) && (controllate w uguaglianze tra
                    // A2[i][k] e A2[j][0...w] && !trovato sse non trovati
                    // duplicati)

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
        // R10: (0<=i<=10) && (sono stati stampati i*j valori)

        for (int j = 0; j < 10; j++) {
            // R11: (0<=i<=5) && (sono stati stampati j valori)

            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "end";
}