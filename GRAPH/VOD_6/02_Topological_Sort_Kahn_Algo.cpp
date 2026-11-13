#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;// No. of vertices

void add_Edge(int src, int des, bool bidirec = true)
{
    graph[src].push_back(des);

    if (bidirec)
    {
        graph[des].push_back(src);
    }
}

void KahnDFSAlgo(){
    vector<int> inDegree(v,0);

    for(int i=0;i<v;i++){
        for(auto  neighbour:graph[i]){
            //i -> neighbour
            inDegree[neighbour]++;
        }
    }

    queue<int> qu;
    unordered_set<int> visited;

    for(int i=0;i<v;i++){
        if(inDegree[i]==0){
            visited.insert(i);
            qu.push(i);
        }
    }


    while(not qu.empty()){
        int node = qu.front();
        qu.pop();
        cout<<node<<"->";
        
        for(auto neighbour : graph[node]){

           if(not visited.count(neighbour)){
             inDegree[neighbour]--;
            if(inDegree[neighbour]==0){
                visited.insert(neighbour);
                qu.push(neighbour);
            }
           }
        }
    }
}

int main()
{

    int  e; // v-vertices, e-edges

    cin >> v >> e;

    graph.resize(v, list<int>());


    while(e--){
        int a, b;
        cin>>a>>b;
        add_Edge(a,b,false);
    }
    KahnDFSAlgo();
}