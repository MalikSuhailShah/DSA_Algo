#include<iostream>
using namespace std;
int main (){// TIME COMPLEXITY= O(n);
    int arr[]={1,4,7,8,5,2,4,5,2,5,18};
    int target=18;
    int idx=-1;
    bool flag=false;

    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=-0;i<n;i++){
        if(arr[i]==target){
            flag=true;
            idx=i;
            break;
        }
    }

    if(flag) cout<<"element present at index "<<idx;
    else cout<<"element not present";
}