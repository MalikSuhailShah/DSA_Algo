#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int main()
{
    string s = "ABCDXXYZYZ";
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch >= 'X')
        {
            str += ch;
        }
    }

    for (int i = 0; i < str.length() - 1; i++)
    {
        bool flag=true;
        for (int j = 0; j < str.length() - 1; j++)
        {
           
            if(str[j]>str[j+1]){
                swap(str[j],str[j+1]);
                flag=false;
            }
        }
        if(flag) break;
    }

    reverse(str.begin(),str.end());
    cout<<str;
}