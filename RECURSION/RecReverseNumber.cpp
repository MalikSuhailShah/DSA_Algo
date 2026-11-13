#include<iostream>
using namespace std;

void ReverseNumber(int n,int & ans){


    if(n==0) return;
    if(n%10==0) n/10;

    int a=n%10;
   ;
    ans= ans*10+a;
    

    return ReverseNumber(n/10, ans);


}
int main (){
    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;
    int ans=0;

    ReverseNumber(n,ans);
    cout<<ans;
}