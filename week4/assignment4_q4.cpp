#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    queue<char> q;
    unordered_map<char, int> m;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        char c = s[i];
        m[c]++;
        if (m[c] == 1)
            q.push(c);

        while (!q.empty() && m[q.front()] > 1)
            q.pop();

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
    return 0;
}
