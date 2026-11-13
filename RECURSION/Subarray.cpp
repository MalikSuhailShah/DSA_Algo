#include<iostream>
#include<vector>
using namespace std;

void Subarray(vector<int> ans,int original[], int n, int idx){
    if(idx==n){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        cout<<endl;
        return;
    }

    Subarray(ans,original,n,idx+1);
    if(ans.size()==0 || original[idx-1]==ans[ans.size()-1]){
        ans.push_back(original[idx]);

        Subarray(ans,original,n,idx+1);
    }
}

int main (){

    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    vector<int> v;
    Subarray(v,arr,n,0);




}