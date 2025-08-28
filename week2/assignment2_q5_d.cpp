#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int upper[size];

    cout << "Enter elements for upper triangular matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (i <= j)
            {
                int index = i * n - (i * (i + 1)) / 2 + j;
                upper[index] = x;
            }
        }
    }

    cout << "\nStored upper triangular elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << upper[i] << " ";
    }

    return 0;
}
