// Articulation point is node removal of which splits the graph into multiple components

#include <iostream>
#include <vector>
#include <list>

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

int timer = 0;

void dfs(int node, int parent, int tin[], int low[], vector<int> &visited, vector<int> &mark)
{
    visited[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    for (auto neighbour : graph[node])
    {
        if (neighbour == parent)
            continue;

        if (!visited[neighbour])
        {
            dfs(neighbour, node, tin, low, visited, mark);

            low[node] = min(low[node], low[neighbour]);

            if (low[neighbour] >= tin[node] && parent != -1)//signifies that the subtree of neighbour cannot reach  any ancestor of node through a back edge. if this particular node is removed and it should not be root of the graph DFS
            {
                mark[node] = 1;
            }
        }
        else
        {
            low[node] = min(low[node], tin[neighbour]);
        }

        child++;
    }

    if (child > 1 and parent == -1)
    {
        mark[node] = 1;
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    graph.resize(n, list<int>());
    while (e--)
    {
        int src, des;
        cin >> src >> des;

        add_Edge(src, des);
    }

    vector<int> visited(n, 0);
    vector<int> mark(n, 0); // mark the node which is articulation point
    int tin[n];
    int low[n];

    for (int i = 0; i < n; i++)
    {
        if (not visited[i])
        {
            dfs(i, -1, tin, low, visited, mark);
        }
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1)
            ans.push_back(i);
    }

    if (ans.size() == 0)
    {
        cout << "No Articulation point!\n";
    }
    else
    {
        cout << "Articulation points are:\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
}