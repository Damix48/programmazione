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
// PRE=(cin contiene x0…xm-1 con m>=0)
nodo* leggi(){
    int temp;
    cin>>temp;
    if(temp!=-1){
        return new nodo(temp, leggi());
    }else{
        return 0;
    }
}
// POST=(restituisce una lista concatenata con m nodi tale che il campo info del nodo 0 sia x0, quello del nodo 1 sia x1, e così via)

void stampa(nodo*L){
    if(L){
    cout<< L->info<<" ";
    stampa(L->next);
    }
}

int main() {
  cout<<"start"<<endl;
  nodo* L= F(0,n);
  stampa_lista(L);
  cout<<"end"<<endl;
}
