#include <iostream>

using namespace std;

bool controlloPartecipante(part, *dati, n){
    
}

int main() {
    int n_part, HH, MM, SS;

    cin >> n_part;
    cin >> HH;
    cin >> MM;
    cin >> SS;

    int letture[n_part * 3][5];

    int n_letture = 0;
    bool finito = false;

    while (!finito) {
        for (int i = 0; i < 5; i++) {
            int temp;
            cin >> temp;
            if (temp == -1) {
                finito=true;
            } else {
                letture[n_letture][i]=temp;
            }
        }
        n_letture++;
    }

    n_letture--;

    cout << "start" << endl;

    for(int i=0;i<n_letture;i++){
        for(int j=0;j<5;j++){
            cout<< letture[i][j]<< ' ';
        }
        cout<<endl;
    }

    for(int i=0;i<n_part;i++)
    {
        int dati[3][5];
        bool t=controlloPartecipante(i,letture, n_letture);
    }
    cout << "end" << endl;
}
