#include<iostream>
#include<string>
using namespace std;
int main ()
{
    string str;
    getline(cin,str);

    int i=0;
    int j=str.length()-1;
    bool flag=true;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            flag=false;
        }
        i++;
        j--;

    }
    if(flag==true) cout<<"string is palindrome";
    else cout<<"string is not palindrome";



}