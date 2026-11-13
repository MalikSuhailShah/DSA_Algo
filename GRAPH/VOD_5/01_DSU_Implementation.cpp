#include <iostream>
#include<vector>

using namespace std;

int find(vector<int> &parent, int x){
    // this method calculates the parent of element x
    //TC= log*n

    return parent[x]=parent[x]==x?x:find(parent, parent[x]);
}


void Union(vector<int>& rank, vector<int> & parent, int a, int b){
    //TC = log*n
    
    a = find(parent, a);
    b = find(parent, b);
    if(a==b) return ;// a and b belongs to the same group
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b]=a;
    } else{
        rank[b]++;
        parent[a]=b;
    }

}

int main ()
{
    // m-queries, n-elements
    int m , n;
    cin>>n>>m;

    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);

    for(int i=0;i<=n;i++){
            parent[i]=i;
    }

    while(m--){
        string str;

        cin>>str;

        if(str=="Union"){
            int a, b;
            cin>>a>>b;
            Union(rank, parent,  a, b);
        }else{
            int x;
            cin>>x;
            cout<<find(parent, x);
        }
    }
    

}