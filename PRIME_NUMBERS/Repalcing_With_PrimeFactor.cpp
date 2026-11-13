#include<iostream>
#include<cmath>
using namespace std;

int PrimeSum(int num){
    int sum=0;

    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            sum=i+(num/i);
        }
    }

    return sum;
}

int main (){

    int num;
    cout<<"Enter the number:"<<endl;
    cin>>num;

    int sum=PrimeSum(num);

    if(sum<=num) num=sum;
    else sum=PrimeSum(num);

    
    


}