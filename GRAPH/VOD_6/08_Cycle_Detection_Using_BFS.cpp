// cycle detection for undirected

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> graph;

void add_Edge(int src, int des, bool bi_direc = true)
{
    graph[src].push_back(des);

    if (bi_direc)
        graph[des].push_back(src);
}

void cycleBFS(int src, bool &cycleExist)
{
   
    queue<pair<int,int>> qu;
    unordered_set<int> visited;

    qu.push({src,-1});
    visited.insert(src);

    while (qu.size())
    {
        
        auto curr = qu.front();
        qu.pop();
        int node = curr.first;
        int parent = curr.second;
        for (int neighbour : graph[node])
        {
            if(not visited.count(neighbour) ){
                qu.push({neighbour,node});
                visited.insert(neighbour);
            }
            else {
                if(parent==neighbour) continue;
                else {
                    cycleExist = true;
                    return;
                }
            }
        }
    }
}

int main()
{

    int v, e;
    cin >> v >> e;
    graph.resize(v, vector<int>());
    while (e--)
    {
        int src, des;
        cin >> src >> des;

        add_Edge(src, des, true);
    }

    int src;
    cin >> src;
   
    bool cycleExist = false;

    cycleBFS(src,cycleExist);

    if (cycleExist)
        cout << "Cycle Exist!!" << endl;
    else
        cout << "No cycle exist" << endl;
}