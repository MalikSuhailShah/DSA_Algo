#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;

    int sqrt=-1;
    bool flag=false;


    int lo=0,hi=n;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        long long m=(long long)mid;

        long long y=(long long )n;
        if(m*m==n) {
            sqrt=m;
            break;
        }

        else if(m*m>n) hi=mid-1;
        else lo=mid+1;
    }

    if(flag) cout<<sqrt;
    else cout<<hi;
    
    
}