#include<iostream>
using namespace std;

int Check(int arr[],int n,int element){
    if(n==0){
        return -1;
    }

    if(element==arr[n-1]) return n-1;

    return Check(arr,n-1,element);
}

int main ()
{
  int arr[]={5,8,2,8,6,2,1,2,6,2,5,2,4,9,6};
  int n=sizeof(arr)/sizeof(arr[0]);

  
  int element;
  cout<<"Enter the number:"<<endl;
  cin>>element;
  cout<<Check(arr,n,element);
}