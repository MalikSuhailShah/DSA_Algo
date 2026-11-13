#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main (){

    vector<int> v(5);
    for(int i=0;i<5;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    cout<<"Ascending sorting:"<<endl;
    for(int i=0;i<5;i++){

        cout<<v[i]<<" ";
    }

    reverse(v.end(),v.begin());

    cout<<endl<<"Descending sorting:"<<endl;
    for(int i=0;i<5;i++){

        cout<<v[i]<<" ";
    }

}