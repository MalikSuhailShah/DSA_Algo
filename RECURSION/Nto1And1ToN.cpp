#include<iostream>
using namespace std;

void Num(int n){
    if(n==0) return;
    cout<<n<<endl;
    Num(n-1);
    cout<<n<<endl;
}
int main (){

    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;

    Num(n);
}