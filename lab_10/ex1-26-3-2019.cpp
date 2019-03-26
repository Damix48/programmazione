#include <iostream>
using namespace std;

int &TV(int *p, int i, int j, int lim3) {
    int &val = p[j * lim3 + i];
    return val;
}

void stampa(int *A, int i, int lim2, int lim3, int n_ele) {
    int a = 0;
    for (int j = 0; j < lim2 && a < n_ele; j++) {
        // R: Abbiamo stampato le prime i righe dell'array A
        for (int k = 0; k < lim3 && a < n_ele; k++) {
            cout << A[j * lim3 + k] << " ";
            a++;
        }
        cout << endl;
    }
}

int main() {
    int x[100];
    for (int i = 0; i < 100; i++) {
        cin >> x[i];
    }
    int lim1, lim2, lim3;
    cin >> lim1 >> lim2 >> lim3;
    cout << "start" << endl;
    bool stop = false;
    int count = 0;
    while (!stop) {
        int quad[4];
        int a;
        cin >> a;
        if (a != -1) {
            quad[count % 4] = a;
            if ((count + 1) % 4 == 0) {
                int temp = TV(x, quad[0], quad[1], lim3);
                TV(x, quad[0], quad[1], lim3) = TV(x, quad[2], quad[3], lim3);
                TV(x, quad[2], quad[3], lim3) = temp;
                // cout << temp<<endl;
            }
        } else {
            stop = true;
        }
        count++;
    }
    // ciclo che invoca TV da fare
    int piene = 100 / (lim2 * lim3);
    for (int i = 0; i < piene + 1 && i < lim1; i++) {
        int ele = lim2 * lim3;
        if (i == piene) {
            ele = (100 % (lim2 * lim3));
        }
        stampa(x + (lim2 * lim3 * i), i, lim2, lim3, ele);
    }
    cout << "end" << endl;
}
