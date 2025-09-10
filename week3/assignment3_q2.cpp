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

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Stack s;

    for (char c : str)
        s.push(c);

    cout << "Reversed string: ";
    while (!s.isEmpty())
        cout << s.pop();

    cout << "\n";
    return 0;
}
