#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main (){
  vector<int> v={10,1,2,5,8,9,7,6,3,11};
   priority_queue<int> pq;

   

   for(int ele : v){
    cout<<ele<<" ";
    pq.push(ele);
   }
   cout<<endl;
   int idx=v.size()-1;
   while(pq.size()){
    int x=pq.top();
    pq.pop();
    v[idx--]=x;
    
   }

   for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
   }
}