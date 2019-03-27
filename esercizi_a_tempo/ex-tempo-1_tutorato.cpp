#include <iostream>
using namespace std;

int main() {
    int A1[10][5];
    int A2[10][5];

    bool B[10][10];

    for (int i = 0; i < 50; i++) {
        // R1: (0<=i<=50) && (sono stati letti `i` valori)

        int n = 0;
        cin >> n;
        A1[i / 5][i % 5];
        A2[i % 10][i / 10];
    }

    cout << "start" << endl;

    // PRE: A1 contiene 50 valori; cout è vuoto
    for (int i = 0; i < 10; i++) {
        // R2': (0<=i<=10) && (cout contiene i righe di valori)
        // R2: (0<=i<=10) && (sono stati stampati i*j valori)

        for (int j = 0; j < 5; j++) {
            // R3': (0<=i<=5) && (cout contiene nella i-esima riga j valori
            // della riga i di A1) oppure (cout contine i valori A1[i][0..j-1])
            // R3: (0<=i<=5) && (sono stati stampati j
            // valori)

            cout << A1[i][j] << " ";
        }
        cout << endl;
    }
    // POST: A1 contiene 50 valori; cout contiene i 50 valori di A1 con un endl
    // dopo l'ultimo valore di ogni riga **(divisi in righe e colonne come A1)

    for (int i = 0; i < 10; i++) {
        // R4: (0<=i<=10) && (sono stati stampati i*j valori)

        for (int j = 0; j < 5; j++) {
            // R5: (0<=i<=5) && (sono stati stampati j valori)

            cout << A2[i][j] << " ";
        }
        cout << endl;
    }

    // SI PUO' CONTROLLARE META' MATRICE DATO CHE E' SIMMETRICA

    for (int i = 0; i < 10; i++) {
        // R6':
        // R6: (0<=i<=10) && (sono stati scritti i*j valori in
        // B[0][0]...B[i][j])

        // con j = i si controlla solo una parte della matrice (in questo a caso
        // a destra della diagonale della matrice)
        for (int j = i; j < 10; j++) {
            // R7':
            // R7: (0<=i<=10) && (sono stati scritti j valori in
            // B[i][0]...B[i][j])

            bool trovato = false;
            int k = 0;

            while (k < 5 && !trovato) {
                // R8': (0<=k<=5) && (trovato==false SSE i primi k valori di i
                // non esiste un valore uguale in j)

                // R8: (0<=k<=5) && (controllate k*w uguaglianze tra
                // A2[i][0...k] e A2[j][0...w] && !trovato sse non trovati
                // duplicati)

                int w = 0;
                while (w < 5 && !trovato) {
                    // R9': (0<=w<=5) && (trovato==false SSE i primi w valori
                    // della riga j di A2 sono tutti diversi da A2[i][0..k])
                    // R9: (0<=w<=5) && (controllate w uguaglianze tra A2[i][k]
                    // e A2[j][0...w] && !trovato sse non trovati duplicati)

                    trovato = A2[i][k] == A2[j][w];
                    w++;
                }
                k++;
                B[i][j] = B[j][i] !trovato;
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