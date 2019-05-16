#include <iostream>

using namespace std;

struct nodo {
    int chiave;
    nodo *next;
    nodo(int c, nodo *n = NULL) {
        chiave = c;
        next = n;
    }
};

struct coda {
    nodo *inizio;
    nodo *fine;
    coda() { inizio = fine = 0; }
};

void push(int c, coda &Q) {
    nodo *temp = new nodo(c);

    if (!Q.inizio) {
        Q.inizio = temp;
    } else {
        Q.fine->next = temp;
    }
    Q.fine = temp;
}

int pop(coda &Q) {
    if (!Q.inizio) {
        return '\0';
    } else {
        nodo *temp = Q.inizio;
        int c = temp->chiave;
        if (Q.inizio == Q.fine) {
            Q.inizio = Q.fine = 0;
        } else {
            Q.inizio = temp->next;
        }
        delete (temp);
        return c;
    }
}

bool e_vuota(coda Q) {
    if (!Q.inizio && !Q.fine) {
        return true;
    }
    return false;
}

// IMPLEMENTARE I METODI DELLA LIBRERIA `coda`

int main() {
    coda Q;
    cout << "start" << endl;

    int n, k;
    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++) {
        push(i, Q);
    }

    while (Q.inizio != Q.fine) {
        for (int i = 0; i < k-1; i++) {
            push(pop(Q), Q);
        }
        cout << pop(Q) << " eliminata" << endl;
    }
    cout << pop(Q) << " sopravvive" << endl;

    cout << "end" << endl;
}