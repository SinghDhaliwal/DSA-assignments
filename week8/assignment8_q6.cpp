#include <iostream>
using namespace std;

const int MAXN = 1000;

struct PriorityQueue {
    int a[MAXN];
    int size;
    PriorityQueue() { size = 0; }
};

void swap(int &x, int &y) {
    int t = x; x = y; y = t;
}

void heapifyDown(PriorityQueue &pq, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < pq.size && pq.a[l] > pq.a[largest]) largest = l;
    if (r < pq.size && pq.a[r] > pq.a[largest]) largest = r;
    if (largest != i) {
        swap(pq.a[i], pq.a[largest]);
        heapifyDown(pq, largest);
    }
}

void heapifyUp(PriorityQueue &pq, int i) {
    while (i != 0) {
        int p = (i - 1) / 2;
        if (pq.a[p] < pq.a[i]) {
            swap(pq.a[p], pq.a[i]);
            i = p;
        } else break;
    }
}

void push(PriorityQueue &pq, int x) {
    if (pq.size == MAXN) return;
    pq.a[pq.size] = x;
    heapifyUp(pq, pq.size);
    pq.size++;
}

int top(PriorityQueue &pq) {
    if (pq.size == 0) return -1;
    return pq.a[0];
}

void pop(PriorityQueue &pq) {
    if (pq.size == 0) return;
    pq.a[0] = pq.a[pq.size - 1];
    pq.size--;
    heapifyDown(pq, 0);
}

bool empty(PriorityQueue &pq) {
    return pq.size == 0;
}

int main() {
    PriorityQueue pq;
    int ch, x;
    while (cin >> ch) {
        if (ch == 1) {
            cin >> x;
            push(pq, x);
        } else if (ch == 2) {
            cout << top(pq) << endl;
        } else if (ch == 3) {
            pop(pq);
        } else if (ch == 0) break;
    }
}
