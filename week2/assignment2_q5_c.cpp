#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int lower[size];

    cout << "Enter elements for lower triangular matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (i >= j)
            {
                int index = i * (i + 1) / 2 + j;
                lower[index] = x;
            }
        }
    }

    cout << "\nStored lower triangular elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << lower[i] << " ";
    }

    return 0;
}
