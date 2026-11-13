#include<iostream>
#include<cmath>
using namespace std;

void printFactor(int n){
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i*i==n) cout<<i<<endl;
            else cout<<i<<" "<<(n/i)<<endl;
        }
    }
}
int main (){

    int n;
    cout<<"Enter the number:"<<endl;

    cin>>n;

    printFactor(n);

}