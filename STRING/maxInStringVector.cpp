#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
int main()
{

    int n;
    cout<<"Enter the size of string vector:"<<endl;
    cin>>n;
    cin.ignore();

  vector<string> v;

  cout<<"Enter the "<<n<<" strings of integer:"<<endl;
  for(int i=0;i<n;i++)
  {
    string s;
    getline(cin,s);
    v.push_back(s);
  }

  int idx=-1;

  int max=stoi(v[0]);

  string l=v[0];

  for(int i=0;i<n;i++)
  {
    int x=stoi(v[i]);

    if(max<x){
        max=x;
        l=v[i];
        idx=i;
    }
  }

  cout<<"Max integer is "<<max<<" at index "<<idx<<endl;

  cout<<"Original string is "<<l<<endl;
}