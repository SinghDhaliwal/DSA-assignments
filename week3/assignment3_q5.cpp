#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

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
        if (top == SIZE - 1)
            return;
        arr[++top] = x;
    }

    int pop()
    {
        if (top == -1)
            return 0;
        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    Stack s;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            int b = s.pop();
            int a = s.pop();
            if (c == '+')
                s.push(a + b);
            else if (c == '-')
                s.push(a - b);
            else if (c == '*')
                s.push(a * b);
            else if (c == '/')
                s.push(a / b);
        }
    }

    cout << "Result: " << s.pop() << "\n";

    return 0;
}
