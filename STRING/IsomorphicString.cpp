#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()

{
    string s,t;

    cout<<"Enter the strings:"<<endl;
    cin>>s>>t;

    bool flag=true;
    
    
    if (s.size() != t.size())
        flag=false;

   else {
    vector<int> v(150, 1000);

    for (int i = 0; i < s.size(); i++)
    {
        int idx = (int)s[i];

        if (v[idx] == 1000)
            v[idx] = s[i] - t[i];
        else if (v[idx] != (s[i] - t[i]))
            flag= false;
    }

    for (int i = 0; i < 150; i++)
    {
        v[i] = 1000;
    }

    for (int i = 0; i < s.size(); i++)
    {
        int idx = (int)t[i];

        if (v[idx] == 1000)
        {
            v[idx] = t[i] - s[i];
        }
        else if (v[idx] != (t[i] - s[i]))
            flag= false;
    }
   }

    if(flag) cout<<"the strings are  isomorphic";
    else cout<<"the strings are not isomorphic";
}
