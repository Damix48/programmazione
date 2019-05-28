#include "BST.h"
#include <iostream>
using namespace std;
int main() {
    // prepara un albero iniziale non triviale
    nodo *r = new nodo(15, new nodo(7), new nodo(19));
    r->left->right = new nodo(9, new nodo(8));
    r->right->right = new nodo(25, new nodo(22));
    cout << "start" << endl;
    bool stop = false;
    int x;
    while (!stop) {
        cin >> x;
        switch (x) {
        case 0:
            stop = true;
            break;
        case 1:
            stampa_l(r);
            break;
        case 2:
            cin >> x;
            r = insert(r, x);
            stampa_l(r);
            break;
        case 3:
            cin >> x;
            if (search(r, x)) {
                cout << "valore " << x << " presente";
            } else {
                cout << "valore " << x << " non presente";
            }
            break;
        case 4:
            cin >> x;
            if (x == 1) {
                cout << max(r)->info;
            } else if (x == 2) {
                cout << min(r)->info;
            }
            break;
        case 5:
            cout << altezza(r);
            break;
        case 6:
            cout << altMin(r);
            break;
        }
        cout << endl;
    }
    cout << "end";
}
