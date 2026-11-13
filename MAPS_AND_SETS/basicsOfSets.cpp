#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{

    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);

    for(int ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;
    //deletion
    s.erase(5);

    for(int ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;

    int target=40;

    if(s.find(target)!=s.end()){
        cout<<"Exists"<<endl;
    }
    else cout<<"Does Not Exists"<<endl;
    cout<<s.size()<<endl;

}
