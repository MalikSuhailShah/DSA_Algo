#include<iostream>
using namespace std;
int main (){
    int arr[]={0,1,2,3,4,5,7,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);


    //LINEAR APPROACH
    // int missing=arr[0];

    // for(int i=1;i<=n;i++){
    //     if(i!=arr[i]){
    //         missing=i;
    //         break;
    //     }
    // }
    // cout<<missing;

    //BINARY SEARCH

    int ans=-1;

    int lo=0,hi=n-1;

    while(lo<=hi){

        int mid =lo+(hi-lo)/2;
        if(arr[mid]==mid) lo=mid+1;
        else{
            ans=mid; // this may be an answer but there may also be an earlier element which can be an answer due to this we search in lower elements also
         
           hi=mid-1;
        }
    }

    cout<<ans;
}