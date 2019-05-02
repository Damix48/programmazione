#include <iostream>

using namespace std;

// PRE = A è un array di interi && i < j
void inverti(int *A, int i, int j){
    if(i<j){        
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        inverti(A, i+1, j-1);
    }
};
// POST = A viene modificato invertendo l’ordine degli elementi nel sottoarray A[i..j]

void stampa(int *A, int lung){
    if(lung!=0){
        stampa(A, lung-1);
        cout<< A[lung-1]<<" ";
    }
}

int main() 
{
    int lung, primo, ultimo;
    int A[100];
    cin >> lung >> primo >> ultimo;
    for(int i = 0; i < lung; i++) { 
        cin >> A[i];
    }
    cout << "start" << endl;
    // scrivere la vostra implementazione qui

    inverti(A, primo, ultimo);
    stampa(A, lung);
    cout<<endl;
    cout << "end" << endl;
}
