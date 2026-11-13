#include<iostream>
using namespace std;

int Max_Power_Of_2(int n){
    int x=0;
    int nums = n;
    while(nums>0){
        

        x=nums;
        nums=(nums&(nums-1));

    }

    if(x==n) x/=2;

    return x;
}

int Max_Power_Of_Two_2(int n){
   n=n|(n>>1);
   n=n|(n>>2);
   n=n|(n>>4);
   n=n|(n>>8);
   n=n|(n>>16);

   return (n+1)>>1;

}

int main (){

    int num;
    cout<<"Enter the number:"<<endl;
    cin>>num;

    cout<<"Power of two less than number:"<<Max_Power_Of_2(num)<<endl;

    cout<<"Power of two less than number:"<<Max_Power_Of_Two_2(num)<<endl;
   // cout<<"Power of 2 just greater than the given number:"<<2*Max_Power_Of_2(num)<<endl;

}