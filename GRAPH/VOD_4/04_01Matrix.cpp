//leetcode 546 => https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>> &grid, int r, int c)
    {
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));

        queue<pair<int, int>> qu;

        qu.push({r, c});
        visited[r][c] = true;

        qu.push({-1, -1});

        int dis = 1;

        while (qu.size())
        {
            auto curr = qu.front();
            qu.pop();
            if (curr.first == -1 && curr.second == -1)
            {
                dis++;
                if (qu.size())
                    qu.push({-1, -1});
                continue;
            }

            visited[curr.first][curr.second] = true;

            for (int i = 0; i < d.size(); i++)
            {
                int nr = curr.first + d[i].first;
                int nc = curr.second + d[i].second;

                if (nr < 0 || nc < 0 || nr >= grid.size() ||
                    nc >= grid[0].size())
                    continue;

                if (grid[nr][nc] == 0)
                    return dis;

                if (!visited[nr][nc])
                {
                    qu.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        return dis;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> ans(rows, vector<int>(cols, -1));

        queue<pair<int, int>> qu;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    qu.push({i, j});
                }
            }
        }

        while (!qu.empty())
        {
            auto x = qu.front();
            qu.pop();
            int r = x.first;
            int c = x.second;

            for (auto curr : d)
            {
                int dr = curr.first;
                int dc = curr.second;
                int nr = dr + r;
                int nc = dc + c;
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                    continue;
                if (ans[nr][nc] != -1)
                    continue;
                if (ans[nr][nc] == -1)
                    ans[nr][nc] = ans[r][c] + 1;
                qu.push({nr, nc});
            }
        }

        // for (int i = 0; i < rows; i++) {
        //     for (int j = 0; j < cols; j++) {
        //         if (mat[i][j] == 0)
        //             continue;
        //         else
        //             ans[i][j] = bfs(mat, i, j);
        //     }
        // }

        return ans;
    }
};

int main()
{
}