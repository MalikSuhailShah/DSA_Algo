#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"Enter the number of digits of the binary number:"<<endl;
    cin>>n;

    int a[n];

    cout<<"Enter the binary number:"<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int f=1;
    int sum=0;

    for(int i=n-1;i>=0;i--)
    {
        sum+=f*a[i];
        f*=2;

    }

    cout<<"The decimal of the given binary number is "<<sum;
}