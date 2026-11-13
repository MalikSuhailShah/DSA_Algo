#include <iostream>
using namespace std;

class Queue
{
public:
    int f;
    int b;
    int arr[5];
    

    Queue()
    {
        f = 0;
        b = 0;
       
    }

    void push(int val)
    {
        if (b == 5)
        {
            cout << "Queue is full!!" << endl;
            return;
        }
        arr[b] = val;
        b++;
    }

    void pop()
    {
        if (b == 0)
        {
            cout << "Queue is empty!!" << endl;
            return;
        }
        f++;
    }

    int front()
    {
        if (b == 0)
        {
            cout << "Queue is empty!!" << endl;
            return -1;
        }

        return arr[f];
    }

    int back()
    {
        if (b == 0)
        {
            cout << "Queue is empty!!" << endl;
            return -1;
        }

        return arr[b-1];
    }

    int size()
    {
        return b - f;
    }

    bool empty()
    {
        if (b == 0)
            return true;
        else
            return false;
    }

    void display()
    {
        if(b==0){
            cout<<"Queue is empty!!"<<endl;
            return;
        }
        for (int i = f; i < b; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

int main()
{

    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.pop();
    q.display();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;;
    cout<<q.size()<<endl;


}