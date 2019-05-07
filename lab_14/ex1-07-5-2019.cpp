#include <iostream>

using namespace std;

struct nodo {
    char chiave;
    nodo *next;
    nodo(char c = '\0', nodo *n = NULL) {
        chiave = c;
        next = n;
    }
};

struct coda {
    nodo *inizio;
    nodo *fine;
    coda() { inizio = fine = 0; }
};

void push(char c, coda &Q) {
    nodo *temp = new nodo(c);

    if (!Q.inizio) {
        Q.inizio = temp;
    } else {
        Q.fine->next = temp;
    }
    Q.fine = temp;
}

char pop(coda &Q) {
    if (!Q.inizio) {
        return '\0';
    } else {
        nodo *temp = Q.inizio;
        char c = temp->chiave;
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
    // IMPLEMENTARE LA SOLUZIONE DELL'ESERCIZIO UTILIZZANDO LE FUNZIONI ESPOSTE
    // DALLA LIBRERIA `coda`
    // cout << Q.inizio->chiave;
    char x = '0';
    while (x != '.') {

        cin >> x;

        if (x == '*') {
            if (e_vuota(Q)) {
                cout << "vuota ";
            } else {
                cout << pop(Q) << " ";
            }
        } else {
            push(x, Q);
        }
    }
    cout << endl;
    cout << "end" << endl;
}