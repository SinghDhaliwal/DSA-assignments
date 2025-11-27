#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIndex]) minIndex = j;
        swap(a[i], a[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool sorted = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sorted = false;
            }
        }
        if (sorted) break;
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int partitionQ(int a[], int l, int r) {
    int p = a[r], i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] < p) swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = partitionQ(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int choice;
    cin >> choice;

    if (choice == 1) selectionSort(a, n);
    else if (choice == 2) insertionSort(a, n);
    else if (choice == 3) bubbleSort(a, n);
    else if (choice == 4) mergeSort(a, 0, n - 1);
    else if (choice == 5) quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
