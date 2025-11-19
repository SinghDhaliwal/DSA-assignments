#include <bits/stdc++.h>
using namespace std;

class CircularLinkedList {
    struct Node {
        int data;
        Node *next;
        Node(int val) : data(val), next(NULL) {}
    };
    Node *head;

public:
    CircularLinkedList() : head(NULL) {}

    void insertLast(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void displayWithRepeatHead() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        cout << "Output: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertLast(20);
    cll.insertLast(100);
    cll.insertLast(40);
    cll.insertLast(80);
    cll.insertLast(60);

    cll.displayWithRepeatHead();
    return 0;
}
