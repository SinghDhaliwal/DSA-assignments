#include <iostream>
using namespace std;

struct N
{
    int d;
    N *nxt;
};

void add(N *&h, int v)
{
    N *t = new N{v, 0};
    if (!h)
        h = t;
    else
    {
        N *p = h;
        while (p->nxt)
            p = p->nxt;
        p->nxt = t;
    }
}

void rev(N *&h)
{
    N *p = 0, *c = h, *n;
    while (c)
    {
        n = c->nxt;
        c->nxt = p;
        p = c;
        c = n;
    }
    h = p;
}

void pr(N *h)
{
    while (h)
    {
        cout << h->d << "->";
        h = h->nxt;
    }
    cout << "NUll\n";
}

int main()
{
    N *h = 0;
    int x, n;
    cout << "Ent num of elems: ";
    cin >> n;
    if (n <= 0)
        return 0;
    cout << "Inpt elems:\n";
    while (n--)
    {
        cin >> x;
        add(h, x);
    }
    cout << "Bfore rev:\n";
    pr(h);
    rev(h);
    cout << "Aftr revrs:\n";
    pr(h);
    return 0;
}
