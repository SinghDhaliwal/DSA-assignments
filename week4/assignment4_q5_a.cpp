#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
    }
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    st.pop();
    cout << "Empty? " << (st.empty() ? "yes" : "no") << endl;
    return 0;
}
