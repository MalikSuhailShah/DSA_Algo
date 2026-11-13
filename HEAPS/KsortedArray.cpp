#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main (){
        vector<int> v={10,9,8,7,4,70,60,50};
        int n=v.size();
        int k=4;
        
        // vector<int> ans;
        priority_queue<int, vector<int>, greater<int> > pq;

        int idx=0;
        for(int i=0;i<n;i++){
            pq.push(v[i]);
            if(pq.size()>k){
               v[idx++]=pq.top();
               pq.pop();
            }
        }

        while(pq.size()){
           v[idx++]=pq.top();
            pq.pop();
        }

        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
         
}