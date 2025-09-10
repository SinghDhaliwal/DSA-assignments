#include <iostream>
using namespace std;

#define SIZE 5

class Stack
{
    int arr[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = x;
        cout << "Pushed " << x << "\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped " << arr[top--] << "\n";
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == SIZE - 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top is " << arr[top] << "\n";
    }
};

int main()
{
    Stack s;
    int choice, value;

    while (true)
    {
        cout << "\n1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (s.isEmpty())
                cout << "Yes\n";
            else
                cout << "No\n";
            break;
        case 4:
            if (s.isFull())
                cout << "Yes\n";
            else
                cout << "No\n";
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.peek();
            break;
        case 7:
            return 0;
        default:
            cout << "Wrong choice\n";
        }
    }

    return 0;
}