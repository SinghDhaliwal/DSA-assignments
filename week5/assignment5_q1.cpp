#include <iostream>
using namespace std;
class Node
{
public:
    int list;
    Node *next;

    Node(int value)
    {
        list = value;
        next = nullptr;
    }
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    void insertatstart(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertatend(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void insertspecific(int value, int target)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current != nullptr && current->list != target)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Target value not found.\n";
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
    void deleteatbeginning()
    {
        if (head == nullptr)
        {
            cout << "list is empty\n";
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void deletefromend()
    {
        if (head == nullptr)
        {
            cout << "list is empty\n";
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }
    void deletespecific(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        Node *pre = nullptr;

        while (temp != nullptr && temp->list != value)
        {
            pre = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value not found\n";
            return;
        }

        if (pre == nullptr)
        {
            head = head->next;
        }
        else
        {
            pre->next = temp->next;
        }

        delete temp;
    }
    void searchelement(int value)
    {
        Node *current = head;
        int pos = 0;
        while (current != nullptr)
        {
            if (current->list == value)
            {
                cout << "Value found at position: " << pos << endl;
            }
            current = current->next;
            pos++;
        }
        cout << "Value not found.\n";
    }
    void displayall()
    {
        Node *current = head;
        if (current == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "List elements: ";
        while (current != nullptr)
        {
            cout << current->list << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    cout << "hello\n";
    int choice, value, target;
    int loop = 1;
    LinkedList list;
    while (loop == 1)
    {
        cout << "enter a number from the following\n";
        cout << "1: insert element at beginning\n2: insert element at end\n3: insert element after a specific value\n4: delete element from beginning\n";
        cout << "5: delete element from end\n6: delete a specific element\n7: search and display\n8: display all node values\n9: exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the value you want to insert at start\n";
            cin >> value;
            list.insertatstart(value);
            break;
        case 2:
            cout << "enter the value you want to insert at end\n";
            cin >> value;
            list.insertatend(value);
            break;
        case 3:
            cout << "enter the value you want to insert\n";
            cin >> value;
            cout << "enter the previous value of the element\n";
            cin >> target;
            list.insertspecific(value, target);
            break;
        case 4:
            list.deleteatbeginning();
            break;
        case 5:
            list.deletefromend();
            break;
        case 6:
            cout << "enter the value you want to delete\n";
            cin >> value;
            list.deletespecific(value);
            break;
        case 7:
            cout << "Enter the value to search\n";
            cin >> value;
            list.searchelement(value);
            break;
        case 8:
            list.displayall();
            break;
        case 9:
            loop = 0;
            break;
        default:
            cout << "invalid choice! \n please enter a valid number" << endl;
            break;
        }
    }
}
