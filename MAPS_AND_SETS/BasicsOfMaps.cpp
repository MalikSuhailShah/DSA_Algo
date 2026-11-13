#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{

    unordered_map<string, int> mp;

    mp.insert({"Malik", 1});

    pair<string, int> p1;
    p1.first = "Suhail";
    p1.second = 2;
    mp.insert(p1);

    // pair<string, int> p2;
    // p2.first = "Alam";
    // p2.second = 3;
    // mp.insert(p2);

    mp["Ritesh"] = 4;

    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout<<mp.size()<<endl;
    mp.erase("Ritesh");
    cout<<mp.size()<<endl;
}