#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6};
    int n = 6;
    int missing = findMissingNumber(arr, n);
    cout << "Missing number is: " << missing << endl;

    return 0;
}
