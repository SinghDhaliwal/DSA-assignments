#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int sym[size];

    cout << "Enter elements of symmetric matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x;
            cin >> x;
            int index = i * (i + 1) / 2 + j;
            sym[index] = x;
        }
    }

    cout << "\nStored symmetric matrix (lower triangle only):\n";
    for (int i = 0; i < size; i++)
    {
        cout << sym[i] << " ";
    }

    return 0;
}
