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
// PRE=(L(n) è una lista ben formata, e cin contiene una sequenza di m valori v1,..,vm (m>=0) seguita da -1)
nodo* F(nodo*n){
	int t;
	cin>>t;
	if(t==-1){
		return 0;
	}
	
}
// POST=(restituisec la lista ordinata composta dai nodi di L(n) e con m nodi aggiuntivi che contengono i valori v1…vm)

// PRE=(L(n) è una lista ben formata e ordinata)
nodo* inserisci(nodo*n,int x){

}
// POST=(restituisce la lista ben formata e ordinata ottenuta da L(n) inserendo un nuovo nodo con campo info=x nella posizione opportuna)

void stampa_lista(nodo*L){
    if(L){
    cout<< L->info<<" ";
    stampa_lista(L->next);
    }
}

int main() {
    cout<<"start"<<endl;
    nodo* L= F(0);
    stampa_lista(L);
    cout<<"end"<<endl;
}
