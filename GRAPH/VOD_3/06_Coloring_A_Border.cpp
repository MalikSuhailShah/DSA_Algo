//leetCode - 1034

#include<iostream>

#include<vector>
#include<list>
#include<unordered_set>

using namespace std;
class Solution {
public:
    vector<pair<int, int>> border;
    bool isBorderCell(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if (row == 0 || row == m - 1 || col == 0 || col == n - 1)
            return true;
        if (row + 1 < m and grid[row][col] != grid[row + 1][col])
            return true;
        if (row - 1 >= 0 and grid[row][col] != grid[row - 1][col])
            return true;
        if (col + 1 < n and grid[row][col] != grid[row][col + 1])
            return true;
        if (col - 1 >= 0 and grid[row][col] != grid[row][col - 1])
            return true;

        return false;
    }
    vector<vector<bool>> vis;
    void dfs(vector<vector<int>>& grid, int row, int col, int color,
             int origColor) {
        int m = grid.size(), n = grid[0].size();

        if (row >= m or row < 0 or col >= n or col < 0)
            return;
        if (grid[row][col] != origColor or vis[row][col])
            return;

        vis[row][col] = true;

        if (isBorderCell(grid, row, col))
            border.push_back({row, col});

        dfs(grid, row + 1, col, color, origColor);
        dfs(grid, row - 1, col, color, origColor);
        dfs(grid, row, col + 1, color, origColor);
        dfs(grid, row, col - 1, color, origColor);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {

        int m = grid.size();
        if (m == 0)
            return grid;
        int n = grid[0].size();

        int origColor = grid[row][col];

        vis.resize(m, vector<bool>(n, false));
        border.clear();

        dfs(grid, row, col, color, origColor);

        for (auto ele : border) {
            int r = ele.first, c = ele.second;
            grid[r][c] = color;
        }

        return grid;
    }
};

int main (){
    
}