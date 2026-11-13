#include <iostream>
#include <vector>
using namespace std;

class circularQueue
{
public:
    int f;
    int b;
    int s;
    int c;
    vector<int> arr;

    circularQueue(int val)
    {
        f = 0;
        b = 0;
        s = 0;
        c = val;
        vector<int> v(val);
        arr = v;
    }

    void push(int val)
    {
        if (s == c)
        {
            cout << "Queue is full!!" << endl;
            return;
        }
        else
        {
            arr[b] = val;
            b++;
            if (b == c)
                b = 0;
            s++;
        }
    }

    void pop()
    {
        if (s == 0)
        {
            cout << "Queue is empty!!" << endl;
            return;
        }
        else
        {
            f++;
            if (f == c)
                f == 0;
            s--;
        }
    }

    int front()
    {
        if (s == 0)
        {
            cout << "Queue is Empty!!" << endl;
            return -1;
        }
        else
        {
            return arr[f];
        }
    }

    int back()
    {
        if (b == 0)
            return arr[c-1];
        else
            return arr[b - 1];
    }

    bool empty()
    {
        if(s==0) return true;
        else return false;
    }

    bool isfull(){
        if(s==c) return true;
        else return false;
    }
};

int main()
{
}