#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

ll minCost(int n, int m, vector<int> & horizontal,vector<int> & vertical){

    sort(vertical.begin(), vertical.end(), cmp);
    sort(horizontal.begin(), horizontal.end(),cmp);

    int v=0,h=0;//two pointers used to track both the sorted arrays
    int hl=1,vr=1;// number of vertical and horizontal boxes at every moment
    ll cost=0;
    while(v < vertical.size() && h < horizontal.size()){
        if(vertical[v]>horizontal[h]){
            cost+=vertical[v]*hl;
            vr++;
            v++;
        }
        else{
            cost+=horizontal[h]*vr;
            hl++;
            h++;
        }
    }

    while(v<vertical.size()){
        cost+=vertical[v]*hl;
        vr++;
        v++;
    }

    while(h<horizontal.size()){
        cost+=horizontal[h]*vr;
        hl++;
        h++;
    }

    return cost;
}
int main (){

    int n, m;
    cout<<"Enter the dimensions of the rectangle:"<<endl;
    cin>>n>>m;

    vector<int> x(n-1);
    for(int i=0;i<n-1;i++){
        int t;
        cin>>t;
        x.push_back(t);
    }

    vector<int> y(m-1);
    for(int i=0;i<m-1;i++){
        int t;
        cin>>t;
        y.push_back(t);
    }

    cout<<minCost(n,m,x,y)<<endl;

}