#include<iostream>
using namespace std;
int main (){
    int arr[]={1,2,3,4,5,6,7,1};

    int n=sizeof(arr)/sizeof(arr[0]);

    int lo=0,hi=n-1;
    int peak=-1;
    bool flag=false;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            flag=true;
            peak=mid;
            break;
        }
        else if(arr[mid]>arr[mid-1]) lo=mid+1;
        else hi=mid-1;
    }

    cout<<peak;
}