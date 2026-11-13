#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int num){
    if(num==1) return false;

    for(int i=2;i<=sqrt(num);i++){

          if(num%i==0) return false;  
    }

    return true;
}

int main (){

    int num;
    cout<<"Enter the number:"<<endl;
    cin>>num;

    // Fcators of the composite number exist in pair such that half of the factor are smaller than sqrt(num);

    if(isPrime(num)) cout<<"The number is prime!!"<<endl;
    else cout<<"The number is prime!!"<<endl;

}