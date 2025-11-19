#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedList {
    struct Node {
        char data;
        Node *prev, *next;
        Node(char val) : data(val), prev(NULL), next(NULL) {}
    };
    Node *head, *tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void insertLast(char val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome() {
        if (!head) return true;

        Node *left = head;
        Node *right = tail;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void display() {
        Node *temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    string str = "LEVEL";
    for (char ch : str)
        dll.insertLast(ch);

    dll.display();

    if (dll.isPalindrome())
        cout << "Output: True" << endl;
    else
        cout << "Output: False" << endl;

    return 0;
}
