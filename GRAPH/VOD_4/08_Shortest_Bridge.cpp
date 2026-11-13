// leetcode 934 : https://leetcode.com/problems/shortest-bridge/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    queue<pair<int, int>> island;

    int rows, cols;

    void bfs(vector<vector<int>>& grid, int r, int c) {

        queue<pair<int, int>> qu;
        qu.push({r, c});
        grid[r][c] = 2;
        island.push({r,c});
        while (!qu.empty()) {
            auto curr = qu.front();
            qu.pop();
            int r = curr.first, c = curr.second;

            for (int i = 0; i < d.size(); i++) {
                int nr = r + d[i].first;
                int nc = c + d[i].second;

                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                    continue;

                if (grid[nr][nc] == 0 || grid[nr][nc]==2)
                    continue;

                if (grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    qu.push({nr, nc});
                    island.push({nr, nc});
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        bool isfound = false;
        for (int i = 0; i < rows && !isfound; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, i, j);
                    isfound = true;
                    break;
                }
            }
        }

        island.push({-2, -2});

        int count = 0;
        while (!island.empty()) {
            auto curr = island.front();
            island.pop();

            int r = curr.first, c = curr.second;

            if (r == -2 && c == -2) {
                count++;
                if (island.size())
                    island.push({-2, -2});
                continue;
            }

            for (int i = 0; i < d.size(); i++) {
                int nr = r + d[i].first;
                int nc = c + d[i].second;

                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                    continue;

                if (grid[nr][nc] == 1)
                    return count ;

                if (grid[nr][nc] == 2)
                    continue;

                if (grid[nr][nc] == 0) {
                    island.push({nr, nc});
                    grid[nr][nc] = 2;
                }
            }
        }

        return count ;
    }
};

int main (){

}