#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 int main ()
 {
    string s;
    cout<<"Enter the first string:"<<endl;
    getline(cin,s);


    string t;
    cout<<"Enter the second string:"<<endl;
    getline(cin,t);

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s==t) cout<<"Strings are anagram";
    else cout<<"String are not anagram";


 }