#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main (){
    vector<int> v={2,7,4,1,8};
    int n=v.size();
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int ele : v){
        pq.push(ele);
    }

    int totalCost=0;
    while(pq.size()>1){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        totalCost+=(x+y);
        pq.push(x+y);
    }

    cout<<"The Final cost of to connect all the ropes:"<<totalCost<<endl;
}