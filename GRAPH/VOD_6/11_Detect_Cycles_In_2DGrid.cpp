// leetcode 1559 : https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows, cols;
    bool BFS(int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        queue<tuple<int, int, int, int>> qu;

        qu.push({r, c, -1, -1});
        if (visited[r][c] == false)
            visited[r][c] = true;

        char ch = grid[r][c];

        while (qu.size())
        {
            int cr = get<0>(qu.front());
            int cc = get<1>(qu.front());
            int pr = get<2>(qu.front());
            int pc = get<3>(qu.front());
            // auto [cr,cc,pr,pc] = qu.front();
            qu.pop();

            for (int i = 0; i < d.size(); i++)
            {
                int nr = cr + d[i].first;
                int nc = cc + d[i].second;

                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                    continue;
                if (grid[nr][nc] != ch)
                    continue;
                if (pr == nr && pc == nc)
                    continue;

                if (visited[nr][nc] == true)
                {
                    // cycle detected
                    return true;
                }
                else
                {
                    if (grid[nr][nc] == ch)
                    {
                        visited[nr][nc] = true;

                        qu.push({nr, nc, cr, cc});
                    }
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        bool cycle = false;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (visited[i][j] == false)
                {
                    cycle = BFS(i, j, visited, grid);
                    if (cycle)
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
}