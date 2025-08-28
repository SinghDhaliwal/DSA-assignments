#include <iostream>
using namespace std;

const int MAX = 100;

int findValue(int mat[][3], int n, int row, int col)
{
    for (int i = 1; i <= n; i++)
    {
        if (mat[i][0] == row && mat[i][1] == col)
        {
            return mat[i][2];
        }
    }
    return 0;
}

void multiplySparse(int mat1[][3], int mat2[][3], int result[][3])
{
    if (mat1[0][1] != mat2[0][0])
    {
        cout << "Matrix multiplication not possible.\n";
        return;
    }

    int k = 1;
    result[0][0] = mat1[0][0];
    result[0][1] = mat2[0][1];

    for (int i = 0; i < mat1[0][0]; i++)
    {
        for (int j = 0; j < mat2[0][1]; j++)
        {
            int sum = 0;
            for (int m = 0; m < mat1[0][1]; m++)
            {
                int val1 = findValue(mat1, mat1[0][2], i, m);
                int val2 = findValue(mat2, mat2[0][2], m, j);
                sum += val1 * val2;
            }
            if (sum != 0)
            {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = sum;
                k++;
            }
        }
    }

    result[0][2] = k - 1;
}

int main()
{
    int mat1[MAX][3], mat2[MAX][3], result[MAX][3];
    int nz1, nz2;

    cout << "Enter rows, cols, and non-zero elements for Matrix 1: ";
    cin >> mat1[0][0] >> mat1[0][1] >> nz1;
    mat1[0][2] = nz1;

    cout << "Enter Matrix 1 triplets:\n";
    for (int i = 1; i <= nz1; i++)
    {
        cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];
    }

    cout << "Enter rows, cols, and non-zero elements for Matrix 2: ";
    cin >> mat2[0][0] >> mat2[0][1] >> nz2;
    mat2[0][2] = nz2;

    cout << "Enter Matrix 2 triplets:\n";
    for (int i = 1; i <= nz2; i++)
    {
        cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];
    }

    multiplySparse(mat1, mat2, result);

    cout << "\nProduct of matrices (Triplet Form):\n";
    for (int i = 0; i <= result[0][2]; i++)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
    }

    return 0;
}