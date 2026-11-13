#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int src, int des, bool bi_dir = true)
{
    graph[src].push_back(des);
    if (bi_dir)
        graph[des].push_back(src);
}


void dfs(int node, unordered_set<int> & visited){
    visited.insert(node);

    for(auto neighbour : graph[node] ){
        if(not visited.count(neighbour)){
            dfs(neighbour, visited);
        }
    }
}


/* Intution
"Have I already explored this vertex as part of some connected component?"
- If yes, skip it.
- If no, start a new DFS and increase the component count by one. */
int connected_Components(){
    int result = 0 ;
    unordered_set<int> visited;

    for(int i=0;i<v;i++){
        // go to every vertex and if any vertex initialise a dfs then we got one more cc

        if(visited.count(i)==0){//the key i does not exist in the  visited.
            result++;
            dfs(i, visited);
        }
    }

    return result;

}
int main()
{

    cout << "Enter the number of vertices:" << endl;
    cin >> v;
    graph.resize(v, list<int>());

    int e;
    cout<<"Enter the number of edges:"<<endl;
    cin >> e;
    while (e--)
    {
        int src, des;
        cin >> src >> des;
        add_edge(src, des);
    }

    cout<<connected_Components();
}