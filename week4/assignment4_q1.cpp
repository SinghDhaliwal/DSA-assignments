#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE], front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) return;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void display() {
        if (isEmpty()) return;
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void peek() {
        if (isEmpty()) return;
        cout << arr[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "1.Enqueue 2.Dequeue 3.Peek 4.Display 5.IsEmpty 6.IsFull 7.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Yes\n" : "No\n");
                break;
            case 6:
                cout << (q.isFull() ? "Yes\n" : "No\n");
                break;
            case 7:
                return 0;
        }
    }
}
