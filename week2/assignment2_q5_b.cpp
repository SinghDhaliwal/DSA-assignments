#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int tri[3 * n - 2];

    cout << "Enter elements of the tri-diagonal matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (i == j)
                tri[n - 1 + i] = x;
            else if (i == j + 1)
                tri[i - 1] = x;
            else if (i + 1 == j)
                tri[2 * n - 1 + i] = x;
        }
    }

    cout << "\nStored tri-diagonal elements:\n";
    for (int i = 0; i < 3 * n - 2; i++)
    {
        cout << tri[i] << " ";
    }

    return 0;
}
