#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main (){

    string str;

    cout<<"Enter the string:"<<endl;

    getline(cin,str);

    int n=str.length();

    reverse(str.begin()+1,str.begin()+5);

   

    string stp;
    cout<<"Enter the 2nd string:";
    getline(cin,stp);

    string q=str+stp;//appending two string
    cout<<"The final string is "<<q;



}