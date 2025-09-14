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
    int x, k, c = 0;

    cout << "Enter list vals (-1 to end): ";
    while (cin >> x && x != -1)
        ins(H, x);

    cout << "Enter key: ";
    cin >> k;

    N *p = H, *prv = 0;
    while (p)
    {
        if (p->d == k)
        {
            ++c;
            if (prv)
                prv->n = p->n;
            else
                H = p->n;
            N *d = p;
            p = p->n;
            delete d;
        }
        else
        {
            prv = p;
            p = p->n;
        }
    }

    cout << "Count: " << c << endl;
    cout << "Updatd Linked List: ";
    while (H)
    {
        cout << H->d;
        if (H->n)
            cout << "->";
        H = H->n;
    }
    cout << endl;
    return 0;
}
