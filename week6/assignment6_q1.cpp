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

    void insertFirst(int val) {
        Node *newNode = new Node(val);
        if (!head)
            head = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

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

    void insertAfter(int key, int val) {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertFirst(val);
            return;
        }
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        if (!head) return;
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        if (temp == head)
            head = head->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;
        delete temp;
    }

    void searchNode(int key) {
        Node *temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found!\n";
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

class CircularLinkedList {
    struct Node {
        int data;
        Node *next;
        Node(int val) : data(val), next(NULL) {}
    };
    Node *head;

public:
    CircularLinkedList() : head(NULL) {}

    void insertFirst(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

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

    void insertAfter(int key, int val) {
        if (!head) return;
        Node *temp = head;
        do {
            if (temp->data == key) {
                Node *newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found!\n";
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertFirst(val);
            return;
        }
        Node *prev = NULL, *curr = head;
        do {
            if (curr->data == key) {
                Node *newNode = new Node(val);
                newNode->next = curr;
                prev->next = newNode;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node " << key << " not found!\n";
    }

    void deleteNode(int key) {
        if (!head) return;
        Node *curr = head, *prev = NULL;
        do {
            if (curr->data == key)
                break;
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (curr->data != key) {
            cout << "Node " << key << " not found!\n";
            return;
        }

        if (curr == head && curr->next == head) {
            head = NULL;
            delete curr;
            return;
        }

        if (curr == head) {
            Node *last = head;
            while (last->next != head)
                last = last->next;
            head = head->next;
            last->next = head;
            delete curr;
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }

    void searchNode(int key) {
        if (!head) return;
        Node *temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << key << " not found!\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        cout << "List: ";
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

    int choice, val, key, listType;
    while (true) {
        cout << "\nChoose Linked List Type:\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nEnter choice: ";
        cin >> listType;
        if (listType == 3) break;

        cout << "\nMENU:\n1. Insert First\n2. Insert Last\n3. Insert After Node\n4. Insert Before Node\n5. Delete Node\n6. Search Node\n7. Display\n8. Back to Main Menu\n";

        while (true) {
            cout << "\nEnter your choice: ";
            cin >> choice;

            if (choice == 8) break;

            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    (listType == 1) ? dll.insertFirst(val) : cll.insertFirst(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    (listType == 1) ? dll.insertLast(val) : cll.insertLast(val);
                    break;
                case 3:
                    cout << "Enter key and value: ";
                    cin >> key >> val;
                    (listType == 1) ? dll.insertAfter(key, val) : cll.insertAfter(key, val);
                    break;
                case 4:
                    cout << "Enter key and value: ";
                    cin >> key >> val;
                    (listType == 1) ? dll.insertBefore(key, val) : cll.insertBefore(key, val);
                    break;
                case 5:
                    cout << "Enter node value to delete: ";
                    cin >> key;
                    (listType == 1) ? dll.deleteNode(key) : cll.deleteNode(key);
                    break;
                case 6:
                    cout << "Enter node value to search: ";
                    cin >> key;
                    (listType == 1) ? dll.searchNode(key) : cll.searchNode(key);
                    break;
                case 7:
                    (listType == 1) ? dll.display() : cll.display();
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        }
    }
    return 0;
}
