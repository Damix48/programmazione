#include <iostream>
using namespace std;
main()
{
  int N, A[100];
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  cout << "start" << endl;
  //da fare
  int i = 0;
  while (i < N)
  {
    if (A[i] == 1)
    {
      int j = i + 1;
      while (j < N)
      {
        if (A[j] == 0)
        {
          int temp = A[i];
          A[i] = A[j];
          A[j] = temp;
        }
        j++;
      }
    }
    i++;
  }

  for (int i = 0; i < N; i++)
  {
    cout << A[i] << " ";
  }

  cout << "end" << endl;
}
