#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &parent, int x)
{
    // this method calculates the parent of element x
    // TC= log*n

    return parent[x] = parent[x] == x ? x : find(parent, parent[x]);
}

bool Union(vector<int> &rank, vector<int> &parent, int a, int b)
{
    // TC = log*n

    a = find(parent, a);
    b = find(parent, b);
    if (a == b)
        return true; // a and b belongs to the same group
    if (rank[a] >= rank[b])
    {
        rank[a]++;
        parent[b] = a;
    }
    else
    {
        rank[b]++;
        parent[a] = b;
    }

    return false;
}

int main()
{
    // m-queries, n-elements
    int m, n;
    cin >> n >> m; // m = number of edges and n = number of vertices

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    while (m--)
    {
        int a, b; // it is basically a edge 
        cin >> a >> b;
        bool isCycle  = Union(rank, parent, a, b);
        if (isCycle ==true) cout<<"Cycle Detected";
    }
}