#include<iostream>
using namespace std;
#include "lib.h"

nodo* faiLista() {
  int x;
  cin>> x;
  if(x==-1) return 0;
  return new nodo(x, faiLista());
}

int conta(nodo*L)
{
    if(L) return 1 + conta (L->next);
    return 0;
    
}

void stampa(nodoE*X,int n)
{
  if(X)
    {
        if(conta(X->C->primo) == X->N && X->C->primo->info==X->V)
        {
            cout <<"lista "<< n<<" con "<<X->N<<" nodi, con valore "<<X->V<<endl;
            stampa(X->next,n+1);
        }
        else
            cout<<"errore nella lista n."<<n<<endl;
    }
}
main()
{
  cout<<"start"<<endl;
  nodo*K=faiLista();
  nodoE* R=faitutto(K,0);
  stampa(R,0);
    cout<<"end"<<endl;
}
