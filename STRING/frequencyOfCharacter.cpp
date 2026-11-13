#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main ()
{

    //FIRST METHOD
    // string s;
    // cin>>s;
    // int n=s.length();

    // int max=0;

    // for(int i=0;i<n-1;i++)
    // {
    //     int count=1;
    //    // char ch=s[i];
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(s[i]==s[j]) count++;
    //     }
    //     if(max<count) max=count;
    // }

    // for(int i=0;i<n-1;i++)
    // {
    //     int count=1;
    //    // char ch=s[i];
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(s[i]==s[j]) count++;
    //     }
    //     if(max==count)
    //     {
    //         cout<<s[i]<<" "<<max<<endl;        }
    // }


    //SECOND METHOD
    string s;
    cin>>s;
    vector<int> v(26,0);
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        int ascii=(int)ch;
        v[ascii-97]++;
    }

    int max=0;
    for(int i=0;i<26;i++)
    {
        if(max<v[i]) max=v[i];
    }

    for(int i=0;i<26;i++)
    {
        if(max==v[i])  cout<<max<<" "<<(char)(i+97)<<endl;
    }


}