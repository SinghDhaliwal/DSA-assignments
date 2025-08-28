#include <iostream>
using namespace std;

const int MAX = 100;

void transpose(int mat[][3], int trans[][3])
{
    int k = 1;
    trans[0][0] = mat[0][1];
    trans[0][1] = mat[0][0];
    trans[0][2] = mat[0][2];

    for (int i = 0; i < mat[0][1]; i++)
    {
        for (int j = 1; j <= mat[0][2]; j++)
        {
            if (mat[j][1] == i)
            {
                trans[k][0] = mat[j][1];
                trans[k][1] = mat[j][0];
                trans[k][2] = mat[j][2];
                k++;
            }
        }
    }
}

int main()
{
    int mat[MAX][3], trans[MAX][3];
    int rows, cols, nonZero;

    cout << "Enter number of rows, columns, and non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = nonZero;

    cout << "Enter the triplets (row, col, value):\n";
    for (int i = 1; i <= nonZero; i++)
    {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    transpose(mat, trans);

    cout << "\nTranspose (Triplet Form):\n";
    for (int i = 0; i <= trans[0][2]; i++)
    {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << endl;
    }

    return 0;
}
