#include<iostream>
#include<map>
using namespace std;
int main (){
    map<int,string> m;

    m[2]="lokesh";
    m[1]="Ritesh";
    m[4]="anupam";
    m[3]="Rohit";

    for(auto x : m){
        cout<<x.first<<" "<<x.second<<endl;
    }
    

}