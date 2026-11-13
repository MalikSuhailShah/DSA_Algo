#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

struct Edge{
    int src;
    int des;
    int wt;
};

bool cmp(Edge E1, Edge E2){
    return E1.wt<E2.wt; // return smaller weighted Edge
}

int find(vector<int> & parent, int x){
    return parent[x] = (parent[x]==x)?x:find(parent,parent[x]);
}

void Union(vector<int> & parent, vector<int> & rank,int a, int b){
    a=find(parent,a);
    b=find(parent,b);

    if(a==b){
        return; // cycle detected
    }

    if(rank[a]>rank[b]){
        rank[a]++;
        parent[b]=a;
    }else{
        rank[b]++;
        parent[a]=b;
    }

    
}

ll krushkal(int n, vector<Edge> & input){
    
    sort(input.begin(),input.end(), cmp);

    vector<int> parent(n+1);
    vector<int> rank(n+1,1);

    for(int i=0;i<=n;i++){
        parent[i]=i;
    }

    int edge_count = 0;
    int i = 0;
    ll ans = 0;

    while(edge_count<n-1 and i < input.size()){
        Edge curr = input[i];

        int srcPar = find(parent, curr.src);
        int desPar = find(parent, curr.des);

        if(srcPar != desPar){
            // include edge as thie will include make cycle
            Union(parent, rank, srcPar, desPar);
            ans+=curr.wt;
            edge_count++;
        }
        i++;
    }

    return ans;

}


int main()
{
    int v;
    cin >> v;
    int e;
    cin >> e;

    vector<Edge> graph(e);

    for(int i=0;i<e;i++){
        cin>>graph[i].src>>graph[i].des>>graph[i].wt;
    }

    cout<<krushkal(v,graph);
    
}