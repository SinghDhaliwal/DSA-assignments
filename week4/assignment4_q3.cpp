#include <iostream>
#include <queue>
#include <limits>
using namespace std;

int getIntInput()
{
    int x;
    while (!(cin >> x))
    {
        cout << "Invalid input. Enter number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return x;
}

void interleave(queue<int> &q)
{
    int n = q.size();
    if (n % 2 != 0)
    {
        cout << "Only even number of elements supported\n";
        return;
    }
    int half = n / 2;
    queue<int> first, second;
    for (int i = 0; i < half; i++)
    {
        first.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        second.push(q.front());
        q.pop();
    }
    while (!first.empty())
    {
        q.push(first.front());
        first.pop();
        q.push(second.front());
        second.pop();
    }
}

int main()
{
    queue<int> q;
    int n;
    cout << "Enter number of elements (even): ";
    n = getIntInput();
    if (n % 2 != 0)
    {
        cout << "Odd size not handled\n";
        return 0;
    }
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        q.push(getIntInput());
    }

    interleave(q);

    cout << "Interleaved: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}
