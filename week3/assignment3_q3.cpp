#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class Stack
{
    char arr[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char c)
    {
        if (top == SIZE - 1)
            return;
        arr[++top] = c;
    }

    char pop()
    {
        if (top == -1)
            return '\0';
        return arr[top--];
    }

    char peek()
    {
        if (top == -1)
            return '\0';
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    if (open == '{' && close == '}')
        return true;
    if (open == '[' && close == ']')
        return true;
    return false;
}

int main()
{
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    Stack s;
    for (char c : expr)
    {
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else if (c == ')' || c == '}' || c == ']')
        {
            if (s.isEmpty() || !isMatching(s.pop(), c))
            {
                cout << "Not balanced\n";
                return 0;
            }
        }
    }

    if (s.isEmpty())
        cout << "Balanced\n";
    else
        cout << "Not balanced\n";

    return 0;
}
