#include <iostream>
#include <queue>
using namespace std;

class Stk
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        int sz = q.size();
        while (sz > 1)
        {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }
    void pop()
    {
        if (q.empty())
            return;
        q.pop();
    }
    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    Stk s;
    s.push(5);
    s.push(15);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
    s.pop();
    cout << "Empty? " << (s.empty() ? "yes" : "no") << endl;
    return 0;
}
