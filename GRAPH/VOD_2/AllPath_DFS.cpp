#include <iostream>
#include <unordered_set>
#include <list>
#include <vector>
using namespace std;

// graph implementation
vector<list<int>> graph;
void add_edge(int src, int dest, bool bi_dir = true)
{
    graph[src].push_back(dest);
    if (bi_dir)
        graph[dest].push_back(src);
}


// DFS
vector<vector<int>> Res;
unordered_set<int> visited;
void dfs(int curr, int end, vector<int> &path)
{

    if (curr == end)
    {
        path.push_back(curr);
        Res.push_back(path);
        path.pop_back();
        return;
    }

    visited.insert(curr);
    path.push_back(curr);

    for (auto neighbour : graph[curr]) 
    {

        if (not visited.count(neighbour))
        {
            dfs(neighbour, end, path);
        }
    }

    visited.erase(curr);
    path.pop_back();

    return;
}

void allPath(int curr, int end)
{
    vector<int> v;
    dfs(curr, end, v);
}

int main()
{

    int v;
    cin >> v;
    graph.resize(v, list<int>());

    visited.clear();

    int e;
    cin >> e;
    while (e--)
    {
        int src, dest;
        cin >> src >> dest;

        add_edge(src, dest);
    }

    int start, end;
    cin >> start >> end;

    allPath(start, end);

    for (auto path : Res)
    {
        for (auto ele : path)
            cout << ele << " ";

        cout << endl;
    }
}

/*
7 8
0 1
0 4
1 3
4 3
1 5
5 6
5 2
2 6
0 6*/