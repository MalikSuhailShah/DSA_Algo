#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

vector<list<int>> graph;

unordered_set<int> visited;

void add_edge(int src, int des, bool bi_dir = true)
{
    graph[src].push_back(des);

    if (bi_dir)
    {
        graph[des].push_back(src);
    }
}

void display()
{

    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "->";
        for (auto ele : graph[i])
        {
            cout << ele << " ";
        }
    }
}

bool dfs(int curr, int end)
{

    if(curr == end) return true;
    visited.insert(curr);

    for (auto neighbour : graph[curr])
    {
        if (not visited.count(neighbour))
        {
            bool result = dfs(neighbour, end);
            if (result)
                return true;
        }
    }

    return false;
}

bool anyPath(int src, int dest)
{
    return dfs(src, dest);
}

int main()
{

    int v;
    cout << "enter the number of vertices:" << endl;
    cin >> v;

    graph.resize(v, list<int>());
    visited.clear();

    int e;
    cout << "enter the number of edges:" << endl;

    cin >> e;

    while (e--)
    {
        int src, des;

        cin >> src >> des;
        add_edge(src, des);
    }

    int start, end;
    cout << "enter the source and desination :" << endl;
    cin >> start >> end;

    cout << anyPath(start, end);
}
/* graph input
7 7
nodes 
0 1
0 4
1 3
1 5
5 6
5 2
6 2
*/