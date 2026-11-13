// to get strongly connnected components

#include <iostream>
#include <vector>
#include <stack>
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
void DFS(int src, unordered_set<int> &visited, stack<int> &st)
{
    visited.insert(src);
    for (auto neighbour : graph[src])
    {
        if (!visited.count(neighbour))
        {

            DFS(neighbour, visited, st);
        }
    }

    st.push(src);
}
void DFS2(int src, unordered_set<int> &visited, vector<list<int>> & transpose)
{
        visited.insert(src);

    for (int neighbour : transpose[src])
    {
        if (!visited.count(neighbour))
            DFS2(neighbour, visited, transpose);
    }
}

int kosaraja_Algo(int n)
{
    unordered_set<int> visited;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
       if(not visited.count(i)){
        DFS(i,visited, st);
       }
    }
    // taking transpose of the graph(create seperate transpose graph instead of updating the original one)

    vector<list<int>> transpose(n);

    for (int i = 0; i < n; i++)
    {
        for (int node : graph[i])
        {
            transpose[node].push_back(i);
        }
    }

    // DFS2 should traverse over transposed graph

    int scc = 0;
    unordered_set<int> visited2;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (not visited2.count(node))
        {
            scc++;
            DFS2(node, visited2, transpose);
        }
    }

    return scc;
}

int main()
{

    int v, e;
    cin >> v >> e;

    graph.resize(v, list<int>());

    while (e--)
    {
        int src, des;
        cin >> src >> des;

        add_Edge(src, des, false);
    }


    cout<<"Number of strongly connected components are :"<<kosaraja_Algo(v)<<"\n";
}