

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
void add_Edge(int src, int des, bool bidir = true)
{
    graph[src].push_back(des);

    if (bidir)
    {
        graph[des].push_back(src);
    }
}
vector<pair<int, int>> ans;
vector<int> tin;
vector<int> low;
vector<int> visited;
int timer = 0;

void DFS(int src, int parent)
{
    visited[src] = 1;
    low[src] = tin[src] = timer++;

    for (auto neighbour : graph[src])
    {
         if (neighbour == parent)
                continue;

        if (visited[neighbour] == -1)
        {
           
            DFS(neighbour, src);

            low[src] = min(low[src], low[neighbour]);

            if (low[neighbour] > tin[src]) // signifies that the subtree of neighbour cannot reach src or any ancestor of src through a back edge. if this particular node is removed
            {
                // bridge Exists
                ans.push_back({src, neighbour});
            }

        }
        else
        {
            low[src] = min(low[src], tin[neighbour]);
        }
    }
}

void trajans_Algo(int n)
{
    tin.resize(n, -1);
    low.resize(n, -1);

    visited.resize(n, -1);

    ans.clear();


    for(int i=0;i<n;i++){
        if(tin[i]==-1){
            // DFS Not performed on this node , handles disconnected 
            DFS(i,-1);
        }
    }
    
}

int main()
{

    int v, e;
    cin >> v >> e;

    while (e--)
    {
        int src, des;
        cin >> src >> des;
        add_Edge(src, des);
    }

    trajans_Algo(v);

    if(ans.size()==0) cout<<"No Bridges not found!!\n";
    else{
        for(auto ele : ans){
            cout<<ele.first<<" "<<ele.second<<"\n";
        }
    }
}