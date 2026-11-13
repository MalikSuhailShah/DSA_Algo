#include<iostream>
#include<queue>
using namespace std;
int main (){
    vector<int> v={10,20,-4,6,18,24,105,118};
    int n=v.size();
    int k;
    cout<<"Enter the value of the k:"<<endl;
    cin>>k;
    priority_queue<int, vector<int> ,greater<int>> pq;

    for(int i=0;i<n;i++){
        pq.push(v[i]);
        if(pq.size()>k) pq.pop();
    }

    cout<<pq.top()<<endl;
}