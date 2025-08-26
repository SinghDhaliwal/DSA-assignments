#include <iostream>
using namespace std;
int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
    return n;
}
int main()
{
    int arr[] = {2, 4, 5, 2, 7, 4, 6, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    n = removeDuplicates(arr, n);
    cout << "\nAfter removing duplicates: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}