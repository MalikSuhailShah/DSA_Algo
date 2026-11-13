//if number=sum of the its positive devisors => number is perfect number

#include<iostream>
#include<cmath>
using namespace std;

int sum(int num){

    if(num==1) return num;
    int sum=0;

    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0) sum+=i+(num/i);
    }

    return sum+1;
}

int main (){

    int num ;
    cout<<"Enter the number:"<<endl;
    cin>>num;

    if(num==sum(num)) cout<<"The number is the Perfect number!!"<<endl;
    else cout<<"The number is not Perfect Number!!"<<endl;
}