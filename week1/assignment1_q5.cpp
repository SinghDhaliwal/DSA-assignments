#include <iostream>
using namespace std;

int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int rows = 3, cols = 3;
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < cols; j++)
        {
            rowSum += arr[i][j];
        }
        cout << "Row " << i << ": " << rowSum << endl;
    }
    cout << "\nSum of each column:\n";
    for (int j = 0; j < cols; j++)
    {
        int colSum = 0;
        for (int i = 0; i < rows; i++)
        {
            colSum += arr[i][j];
        }
        cout << "Column " << j << ": " << colSum << endl;
    }

    return 0;
}