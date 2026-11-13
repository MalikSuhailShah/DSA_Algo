// cycle detection for undirected

#include <iostream>
#include<vector>
#include<unordered_set>
#include<climits>


using namespace std;

vector<vector<int>> graph;

void add_Edge(int src, int des, bool bi_direc=true){
    graph[src].push_back(des);

    if(bi_direc) graph[des].push_back(src);
}

void cycleDFS(int src, int parent, unordered_set<int> & visited, bool &cycleExist){
    
    for(auto neighbour : graph[src]){
        if(visited.count(neighbour) and parent == neighbour) continue;
        if(visited.count(neighbour)) {
            cycleExist = true;
            return;
        };
        if(not visited.count(neighbour)){
            visited.insert(neighbour);
            cycleDFS(neighbour,src,visited, cycleExist);
        }
    }
}

int main (){

    int v,e;
    cin>>v>>e;
    graph.resize(v, vector<int> ());
    while(e--){
        int src, des;
        cin>>src>>des;

        add_Edge(src, des, true);
    }

    unordered_set<int> visited;

    int src;
    cin>>src;
    visited.insert(src);
    bool cycleExist = false;
    cycleDFS(src,INT_MIN,visited, cycleExist);

    if(cycleExist) cout<<"Cycle Exist!!"<<endl;
    else cout<<"No cycle exist"<<endl;


}