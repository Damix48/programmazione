#include <iostream>
using namespace std;

struct nodo {
    int info;
    nodo *next;
    nodo(int a = 0, nodo *b = 0) {
        info = a;
        next = b;
    }
};
// PRE=(cin contiene n valori sequiti da -1 con n>=0)
nodo* leggi(){
    int temp;
    cin>>temp;
    if(temp==-1){
        return 0;}
    return new nodo(temp, leggi());
}
// POST=(restituisce una lista concatenata con n nodi tale che il campo info del nodo 0 sia x0, quello del nodo 1 sia x1, e così via)


// PRE=(L è una lista ben formata)
int ricerca(nodo*L, int x){
    if(!L){
        return -1;
    }
    if(L->info==x){
        return 0;
    }
    int y=ricerca(L->next,x);
    if(y==-1){
        return -1;
    }
    return y+1;
    
}
// POST(se esiste un nodo di L con campo info=x allora restituisce la sua posizione in L, altrimenti restituisce -1)

// PRE=(L è una lista ben formata, cin contiene n valori, con n>=0, che sono valori da cercare in L)
void fai_ricerche(nodo*L, int n){
    if(n>0){
        int t;
        cin>>t;
        int index= ricerca(L, t);
        if(index!=-1){
        cout<< "il valore "<< t<<" e' in posizione "<<index<<endl;
        }else{
        cout<< "il valore "<< t<<" non si trova nella lista"<<endl;

        }
        fai_ricerche(L, n-1);
    }
}
// POST=(legge da cin ciascuno degli n valori e li ricerca in L e per ognuno di essi stampa la frase che si applica)



int main() {
    nodo *L = leggi();
    int n;
    cin >> n;
    cout << "start" << endl;
    fai_ricerche(L, n);
    cout << "end" << endl;
}
