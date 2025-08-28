#include <iostream>
using namespace std;

const int MAX = 100;

void addSparse(int mat1[][3], int mat2[][3], int result[][3])
{
    if (mat1[0][0] != mat2[0][0] || mat1[0][1] != mat2[0][1])
    {
        cout << "Matrix dimensions do not match.\n";
        return;
    }

    result[0][0] = mat1[0][0];
    result[0][1] = mat1[0][1];

    int i = 1, j = 1, k = 1;
    while (i <= mat1[0][2] && j <= mat2[0][2])
    {
        if (mat1[i][0] == mat2[j][0] && mat1[i][1] == mat2[j][1])
        {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2] + mat2[j][2];
            i++;
            j++;
            k++;
        }
        else if (mat1[i][0] < mat2[j][0] ||
                 (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1]))
        {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++;
            k++;
        }
        else
        {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++;
            k++;
        }
    }

    while (i <= mat1[0][2])
    {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++;
        k++;
    }

    while (j <= mat2[0][2])
    {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;
}

int main()
{
    int mat1[MAX][3], mat2[MAX][3], result[MAX][3];
    int nz1, nz2;

    cout << "Enter dimensions and non-zero count for Matrix 1 (rows cols nz): ";
    cin >> mat1[0][0] >> mat1[0][1] >> nz1;
    mat1[0][2] = nz1;

    cout << "Enter Matrix 1 triplets:\n";
    for (int i = 1; i <= nz1; i++)
    {
        cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];
    }

    cout << "Enter dimensions and non-zero count for Matrix 2 (rows cols nz): ";
    cin >> mat2[0][0] >> mat2[0][1] >> nz2;
    mat2[0][2] = nz2;

    cout << "Enter Matrix 2 triplets:\n";
    for (int i = 1; i <= nz2; i++)
    {
        cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];
    }

    addSparse(mat1, mat2, result);

    cout << "\nSum of matrices (Triplet Form):\n";
    for (int i = 0; i <= result[0][2]; i++)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
    }

    return 0;
}
