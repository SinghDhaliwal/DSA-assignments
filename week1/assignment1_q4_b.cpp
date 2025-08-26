#include <iostream>
using namespace std;

int main()
{
    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    int B[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}};

    int C[2][2] = {0};

    int rowsA = 2, colsA = 3;
    int rowsB = 3, colsB = 2;

    cout << "Matrix A:\n";
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nMatrix B:\n";
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "\nMatrix A x B (Result):\n";
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
