#include <iostream>
// #include<queue>
#include <vector>
using namespace std;

class Queue
{
    vector<int> v;

public:
    int f;
    int size;

    Queue()
    {
        f = 0;
        size = 0;
    }

    void push(int val)
    {
        
        v.push_back(val);
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            cout << "Queue underflows!!" << endl;
            return;
        }
        else
        {
            f++;
            size--;
        }
    }
    int front()
    {
        if(size==0){
            cout<<"Queue underflows !!"<<endl;;
            return -1;
        }
        return v[f];
    }
    int Size()
    {
        return size;
    }
    bool empty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }
    int rear()
    {
        if(size==0){
            cout<<"Queue underflows!!"<<endl;
            return -1;
        }
       else return v[v.size() - 1];
    }

    void display(){
        for(int i=f;i<v.size();i++){
            cout<<v[i]<<" ";
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
    cout<<q.rear()<<endl;;
    cout<<q.Size()<<endl;
}