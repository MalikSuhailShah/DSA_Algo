#include<iostream>
#include<queue>
using namespace std;
int main (){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(20);
    pq.push(0);
    pq.push(30);
    pq.push(50);
    pq.push(60);
    pq.push(-190);
    pq.push(1);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
}