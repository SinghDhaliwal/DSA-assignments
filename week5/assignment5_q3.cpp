#include <iostream>
using namespace std;

struct N
{
    int d;
    N *n;
    N(int x) : d(x), n(NULL) {}
};

void ins(N *&h, int v)
{
    if (!h)
        h = new N(v);
    else
    {
        N *t = h;
        while (t->n)
            t = t->n;
        t->n = new N(v);
    }
}

int main()
{
    N *H = 0;
    int x;
    cout << "Enter list vals (-1 to stop): ";
    while (cin >> x && x != -1)
        ins(H, x);

    if (!H)
    {
        cout << "Emtpy list\n";
        return 0;
    }

    N *s = H, *f = H;
    while (f && f->n)
    {
        s = s->n;
        f = f->n->n;
    }

    cout << "Middle: " << s->d << endl;
    return 0;
}
