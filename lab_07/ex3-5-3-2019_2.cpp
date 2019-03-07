#include <iostream>
using namespace std;

int main() {
    int N, A[100];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << "start" << endl;
    // da fare
    int i = 0;
    int j = N - 1;
    while (i < N && i < j) {
        if (A[i] == 1) {
            if (A[j] == 0) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            j--;
        } else {
            i++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    cout << "end" << endl;
}
