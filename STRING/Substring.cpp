#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int main ()
{
    string s;
    cout<<"Enter the string:"<<endl;
    getline(cin,s);


    int n=s.size();
    cout<<s.substr(n/2,n/2);
}