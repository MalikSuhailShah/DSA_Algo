#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(5);
    

    for (int i = 0; i < 3; i++)
    {
      cin>>v[i];
    }

    
    for (int i = 0; i < 3; i++)
    {
      cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<v.size();
    
}