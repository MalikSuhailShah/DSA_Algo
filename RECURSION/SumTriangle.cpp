#include<iostream>
#include<vector>
using namespace std;

int SumTriangle(vector<int> &v,int idx,int n){
   
    if(n==0){
        return v[0];
    }

    for(int i=0;i<=n;i++){

        cout<<v[i]<<" ";
        if(i<n){
            v[i]+=v[i+1];
        }
    }
    cout<<endl;
    v.pop_back();

    return SumTriangle(v,idx,n-1);



}
int main (){
   vector<int> v ={5,4,3,2,1};
    int n=v.size()-1;

   cout<<SumTriangle(v,0,n);


}