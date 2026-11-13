//leetcode 417 : https://leetcode.com/problems/pacific-atlantic-water-flow/description/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // directions

    vector<vector<int>> grid;
    int cols, rows;

    vector<vector<bool>> bfs(queue<pair<int, int>>& qu) {

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        while (qu.size()) {

            auto cell = qu.front();
            qu.pop();

            int r = cell.first;
            int c = cell.second;

            visited[r][c] = true;

            for (int i = 0; i < d.size(); i++) {
                int newRow = r + d[i].first;
                int newCol = c + d[i].second;

                if (newRow < 0 || newCol < 0 || newRow > rows - 1 ||
                    newCol > cols - 1)
                    continue;

                if (grid[newRow][newCol] >= grid[r][c] &&
                    !visited[newRow][newCol])
                    qu.push({newRow, newCol});
            }
        }

        return visited;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        rows = heights.size();
        cols = heights[0].size();
        grid = heights;

        queue<pair<int, int>> pacific;
        queue<pair<int, int>> atlantic;

        for (int i = 0; i < cols; i++) {
            pacific.push({0, i});
            atlantic.push({rows - 1, i});
        }

        for (int i = 0; i < rows ; i++) {
            pacific.push({i, 0});
            atlantic.push({i, cols - 1});
        }

        vector<vector<bool>> atlantic_visit = bfs(atlantic);
        vector<vector<bool>> pacific_visit = bfs(pacific);

        vector<vector<int>> ans;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (atlantic_visit[i][j] &&
                    atlantic_visit[i][j] == pacific_visit[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};

int main (){

}