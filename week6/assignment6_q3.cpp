#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedList {
    struct Node {
        int data;
        Node *prev, *next;
        Node(int val) : data(val), prev(NULL), next(NULL) {}
    };
    Node *head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertLast(int val) {
        Node *newNode = new Node(val);
        if (!head)
            head = newNode;
        else {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    int getSize() {
        int count = 0;
        Node *temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node *temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

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

    int getSize() {
        if (!head)
            return 0;
        int count = 0;
        Node *temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void display() {
        if (!head) {
            cout << "Circular Linked List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insertLast(10);
    dll.insertLast(20);
    dll.insertLast(30);
    dll.insertLast(40);

    cll.insertLast(5);
    cll.insertLast(15);
    cll.insertLast(25);
    cll.insertLast(35);

    dll.display();
    cout << "Size of Doubly Linked List = " << dll.getSize() << endl << endl;

    cll.display();
    cout << "Size of Circular Linked List = " << cll.getSize() << endl;

    return 0;
}
