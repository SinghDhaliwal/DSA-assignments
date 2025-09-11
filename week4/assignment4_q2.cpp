#include <iostream>
#include <limits>
using namespace std;

#define SIZE 5

class CQ
{
    int arr[SIZE];
    int f, r;

public:
    CQ() { f = r = -1; }

    bool isEmpty() { return f == -1; }

    bool isFull() { return (r + 1) % SIZE == f; }

    void enq(int x)
    {
        if (isFull())
        {
            cout << "Queue is ful\n";
            return;
        }
        if (isEmpty())
            f = r = 0;
        else
            r = (r + 1) % SIZE;
        arr[r] = x;
        cout << "enqued " << x << "\n";
    }

    void deq()
    {
        if (isEmpty())
        {
            cout << "Que is emptty\n";
            return;
        }
        int d = arr[f];
        if (f == r)
            f = r = -1;
        else
            f = (f + 1) % SIZE;
        cout << "dequed: " << d << "\n";
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Nothing to peep\n";
            return;
        }
        cout << "front is " << arr[f] << "\n";
    }

    void disp()
    {
        if (isEmpty())
        {
            cout << "q is empty\n";
            return;
        }
        cout << "q containts: ";
        int i = f;
        while (1)
        {
            cout << arr[i] << " ";
            if (i == r)
                break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

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

int main()
{
    CQ q;
    int ch, val;
    do
    {
        cout << "\n1.enq  2.deq  3.peek  4.display  5.exit\nchose:";
        ch = getIntInput();
        switch (ch)
        {
        case 1:
            cout << "val:";
            val = getIntInput();
            q.enq(val);
            break;
        case 2:
            q.deq();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.disp();
            break;
        case 5:
            cout << "bye!\n";
            break;
        default:
            cout << "wrong choise\n";
        }
    } while (ch != 5);
    return 0;
}
