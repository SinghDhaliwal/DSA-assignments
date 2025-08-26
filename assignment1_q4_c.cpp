#include <iostream>
using namespace std;

int main()
{
    int rows = 2, cols = 3;
    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    cout << "Original Matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    int transpose[3][2];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = A[i][j];
        }
    }
    cout << "\nTranspose of the Matrix:\n";
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
