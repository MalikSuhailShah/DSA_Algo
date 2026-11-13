#include <iostream>
#include <queue>
using namespace std;

void display(queue<int> &  q){
    int n=q.size();

    int i=0;
    while(i!=n){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
        i++;
    }
    cout<<endl;
}

void removeEle(queue<int> & q){
    int i=0;
    int n=q.size();

    while(i<n){
        if(i%2==0) q.pop();
        else{
            q.push(q.front());
            q.pop();
        }
        i++;
    }
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    removeEle(q);
    display(q);
}