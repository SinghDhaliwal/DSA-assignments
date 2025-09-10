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

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    Stack s;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                postfix += s.pop();
            s.push(c);
        }
    }

    while (!s.isEmpty())
        postfix += s.pop();

    cout << "Postfix expression: " << postfix << "\n";

    return 0;
}
