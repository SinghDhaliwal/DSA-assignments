#include <bits/stdc++.h>
using namespace std;

class LinkedList {
    struct Node {
        int data;
        Node *next;
        Node(int val) : data(val), next(NULL) {}
    };
    Node *head;

public:
    LinkedList() : head(NULL) {}

    void insertLast(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (!head) return;
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (!head) return false;

        Node *temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;

        return (temp == head);
    }

    void display() {
        Node *temp = head;
        cout << "Linked List: ";
        int count = 0;
        while (temp && count < 10) {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        cout << "...\n";
    }
};

int main() {
    LinkedList list;

    list.insertLast(2);
    list.insertLast(4);
    list.insertLast(6);
    list.insertLast(7);
    list.insertLast(5);

    list.makeCircular();

    list.display();

    if (list.isCircular())
        cout << "Output: True" << endl;
    else
        cout << "Output: False" << endl;

    return 0;
}
