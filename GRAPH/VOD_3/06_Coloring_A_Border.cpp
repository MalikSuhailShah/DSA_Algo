//leetCode - 1034

#include<iostream>

#include<vector>
#include<list>
#include<unordered_set>

using namespace std;

vector< list<int> > graph;
int v;


void add_Edge(int src, int des, bool bi_dir = true){
    graph[src].push_back(des);

    if(bi_dir){
        graph[des].push_back(src);
    }
}


void dfs(unordered_set<int> & visited, int node){
    visited.insert(node);

    for(auto neighbour : graph[node]){
        if(not visited.count(neighbour)){
            dfs(visited, neighbour);
        }

    }

}

int main (){
    
}