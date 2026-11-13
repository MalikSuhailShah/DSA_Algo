#include <iostream>
#include<vector>

using namespace std;

int find(vector<int> &parent, int x){
    // this method calculates the parent of element x
    //TC= log*n

    return parent[x]=parent[x]==x?x:find(parent, parent[x]);
}


void Union(vector<int>& rank, vector<int> & parent, vector<int> & minimal, vector<int> & maximal, vector<int> & size, int a, int b){
    //TC = log*n
    
    a = find(parent, a);
    b = find(parent, b);
    if(a==b) return ;// a and b belongs to the same group
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b]=a;
        size[a]+=size[b];
        minimal[a]=min(minimal[a], minimal[b]);
        maximal[a]=max(maximal[a],maximal[b]);

    } else{
        rank[b]++;
        parent[a]=b;
        size[b]+=size[a];
        minimal[b]=min(minimal[a], minimal[b]);
        maximal[b]=max(maximal[a],maximal[b]);

    }

}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // m-queries, n-elements
    int m , n;
    cin>>n>>m;

    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);
    vector<int> size(n+1,1);

    for(int i=0;i<=n;i++){
            parent[i]=minimal[i]=maximal[i]=i;
    }

    while(m--){
        string str;

        cin>>str;

        if(str=="Union"){
            int a, b;
            cin>>a>>b;
            Union(rank, parent,minimal, maximal, size, a, b);
        }else{
            int x;
            cin>>x;
            x=find(parent, x);// basically getting the group leader so that we can get minimal and maximal of that group
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<size[x]<<"\n";
        }
    }
    

}