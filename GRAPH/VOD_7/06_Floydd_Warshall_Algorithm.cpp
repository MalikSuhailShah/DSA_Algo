
#include <iostream>
#include <vector>
#include <algorithm>

#define pp pair<int, int>
using namespace std;

vector<vector<pp> > graph;

vector<vector<int> > floyd_warshall()
{
    int n = graph.size();
    vector<vector<int> > ans(n, vector<int>(n, 1e9));

    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 0;
        for (auto it : graph[i])
        {
            int j = it.first;
            int wt = it.second;

            ans[i][j] = min(wt, ans[i][j]);
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans[i][k] != 1e9 and ans[k][j] != 1e9)
                    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i][i] < 0)
        {
            cout << "Negative cycle exist!\n";
            return {};
        }
    }

    return ans;
}

int main()
{

    int n, m;
    cin >> n >> m;

    graph.resize(n, vector<pp>());

    while (m--)
    {
        int src, des, wt;
        cin >> src >> des >> wt;

        graph[src].push_back({des, wt});
    }

    vector<vector<int> > ans = floyd_warshall();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}