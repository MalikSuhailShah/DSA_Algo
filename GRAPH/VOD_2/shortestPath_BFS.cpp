#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<climits>
#include<unordered_set>
using namespace std;


vector<list<int>> graph;
int v;
unordered_set<int> visited;

void add_Edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}


void bfs(int src,  vector<int> & distance)
{
    distance.resize(v,INT_MAX );

    queue<int> qu;
    distance[src]=0;
    qu.push(src);
    visited.insert(src);

    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        cout<<curr<<" ";
        for(auto neighbour : graph[curr]){
            if(not visited.count(neighbour)){
                qu.push(neighbour);
                visited.insert(neighbour);
                distance[neighbour] = distance[curr]+1; // will give the shortest distance posible
            }
        }
    }
    cout<<endl;

}
int main (){

    cin>>v;

    graph.resize(v, list<int> ());
    visited.clear();
    int e;
    cin>>e;

    while(e--){
        int src,dest;
        cin>>src>>dest;

        add_Edge(src, dest);
    }

    vector<int> distance;

    int x;
    cin>>x;
    
 // no need of destination node , shortest distance of every node from source  is calculated

    bfs(x,distance);

    for(int i=0;i<distance.size();i++) cout<<distance[i]<<" ";
}