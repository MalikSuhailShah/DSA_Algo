#include<iostream>
using namespace std;

void tower(int n, char s,char h,char d){
    if(n==0) return ;
    tower(n-1,s,d,h);
    cout<<s<<"->"<<d<<endl;
    tower(n-1,h,s,d);
    return;
}
int main (){
    int n;
    cout<<"Enter the number of disk:"<<endl;
    cin>>n;

    tower(n,'A','B','C');// A-> source rod,B->helper rod,C->destination rod
}