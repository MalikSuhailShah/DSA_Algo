// greedy choice : Start from one vertex and repeatedly add the cheapest edge that connects a vertex already in the tree to a vertex outside it.

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <climits>

#define pp pair<int, int>
#define ll long long int

using namespace std;

vector<list<pp>> graph;

void add_Edge(int src, int des, int wt, bool bi_Dir = true)
{
    graph[src].push_back({des, wt});
    if (bi_Dir)
    {
        graph[des].push_back({src, wt});
    }
}

ll prims(int src, int n)
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_map<int, int> mp;//Stores the smallest edge weight discovered so far for each vertex
    unordered_set<int> visited;

    vector<int> parent(n + 1);

    pq.push({0, src});

    for (int i = 1; i <= n; i++)
    {
        mp[i] = INT_MAX;
    }

    mp[src] = 0;
    int total_Count = 0;
    ll result = 0;

    while (total_Count < n && !pq.empty())
    {
        pp curr = pq.top();

        int currNode = curr.second;
        int currWeight = curr.first; // it is wight of currNode from its parent node

        if (visited.count(currNode))
        {
            pq.pop();
            continue;
        }

        visited.insert(currNode); // we are visiting the node only while processing from the queue

        total_Count++;
        result += currWeight;
        pq.pop();

        for (auto neighbour : graph[currNode])
        {
            int NeighbourNode = neighbour.first;
            int NeighbourWeight = neighbour.second;
            if (!visited.count(NeighbourNode) and mp[NeighbourNode] > NeighbourWeight ) // no need to check for the parent node because parent node is already visited
            {
                pq.push({NeighbourWeight, NeighbourNode});
                mp[NeighbourNode] = NeighbourWeight;
                parent[NeighbourNode] = currNode;
            }
        }
    }



    if (total_Count != n)// handles the condition of disconnected graph
    return -1;

    return result;
}
int main()
{

    int m, n;
    cin >> m >> n;

    graph.resize(n+1, list<pp> ());

    while (m--)
    {
        int a, b, wt;
        cin >> a >> b >> wt;

        add_Edge(a, b, wt);
    }

    int src;
    cin >> src;

    cout<<prims(src,n);
}