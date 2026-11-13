#include<iostream>
using namespace std;
#include<climits>
int main ()
{
    int n;
    cout<<"enter the size of array->";
    cin>>n;
    int arr[n];
    cout<<"enter the value of elements of array->";
    for(int i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }
    int max=INT_MIN;
    for(int i=0;i<=n-1;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    cout<<max;
    
}