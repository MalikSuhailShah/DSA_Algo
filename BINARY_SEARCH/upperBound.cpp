#include<iostream>
using namespace std;
int main (){

    int arr[] = {1, 2, 9, 10, 15, 18, 21, 25, 27};
    int n=sizeof(arr)/sizeof(arr[0]);

    int x;
    cout<<"Enter the inetger:"<<endl;
    cin>>x;

    int lo=0;
    int hi=n-1;
    bool flag=false;

    while(lo<=hi){
    
        int mid=lo+(hi-lo)/2;

        if(x==arr[mid]){
            flag=true;
            cout<<"upper bound:"<<arr[mid+1];
            break;
        }
        else if(arr[mid]<x) lo=mid+1;
        else hi=mid-1;
    }

    if(!flag) cout<<"upper bound:"<<arr[lo];
}