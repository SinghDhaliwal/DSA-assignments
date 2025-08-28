#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int diag[n];

    cout << "Enter elements for diagonal matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (i == j)
                diag[i] = x;
        }
    }

    cout << "\nStored diagonal elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << diag[i] << " ";
    }

    return 0;
}
