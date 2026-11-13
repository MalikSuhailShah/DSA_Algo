// leetcode 994 :- https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> h;
    int rows, cols;

    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int orangesRotting(vector<vector<int>> &grid)
    {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> rottenOranges;
        int totalOranges = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1 or grid[i][j] == 2)
                    totalOranges++;

                if (grid[i][j] == 2)
                    rottenOranges.push({i, j});
            }
        }
        int totalRotten = rottenOranges.size();
        rottenOranges.push({-1, -1});

        int c = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        while (!rottenOranges.empty())
        {
            auto curr = rottenOranges.front();
            rottenOranges.pop();

            if (curr.first == -1 && curr.second == -1)
            {
                c++;
                if (rottenOranges.size())
                    rottenOranges.push({-1, -1});
                continue;
            }

            visited[curr.first][curr.second] = true;

            for (int i = 0; i < d.size(); i++)
            {
                int newRow = curr.first + d[i].first;
                int newCol = curr.second + d[i].second;

                if (newRow < 0 || newCol < 0 || newRow >= rows ||
                    newCol >= cols)
                    continue;

                if (!visited[newRow][newCol] && grid[newRow][newCol] == 1)
                {
                    rottenOranges.push({newRow, newCol});
                    grid[newRow][newCol] = 2;
                    totalRotten++;
                }
            }
        }

        return (totalRotten == totalOranges) ? c - 1 : -1; // first oranges are already rotten
    }
};

int main()
{
}