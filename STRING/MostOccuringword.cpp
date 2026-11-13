#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
int main()
{

    string s;

    cout << "Enter the string:" << endl;
    getline(cin, s);

    stringstream ss(s);
    string temp;

    vector<string> v;

    while (ss >> temp)
    {
        v.push_back(temp);
    }

    sort(v.begin(), v.end());// sorting enable us to use only one loop while checking for the same word

    int count = 1, maxcount = 0;

    for (int i = 1; i < v.size(); i++)
    {

        if (v[i] == v[i - 1])
            count++;
        else
            count = 1;

        if (maxcount < count)
            maxcount = count;
    }

    count=1;
    
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==v[i-1]) count++;
        else count=1;

        if(maxcount==count) cout<<v[i]<<"->"<<maxcount<<endl;
    }
}