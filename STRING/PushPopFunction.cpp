#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main (){
    string s;

    cout<<"Enter the string:"<<endl;
    getline(cin,s);

    s.push_back('d');

    cout<<"after pushing character d string is :"<<s<<endl;

    s.pop_back();

    cout<<"string after popping the last character:"<<s;


}