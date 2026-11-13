// calculate number of ways to reach bottom right cell from top left cell in the given grid or maze

#include <iostream>
#include <vector>

using namespace std;

bool canWeGo(vector<vector<int>> &grid, int n, int i, int j)
{
    return i < n and j < n and i >= 0 and j >= 0 and grid[i][j] == 0;
}

int ans = 0;
void f(vector<vector<int>> &grid, int n, int i, int j)
{
    if (i == n - 1 and j == n - 1)
    {
        ans += 1;
        return;
    }

    grid[i][j] = 2; // means cell is visited

    // left
    if (canWeGo(grid, n, i, j - 1))
    {
        f(grid, n, i, j - 1);
    }
    // right
    if (canWeGo(grid, n, i, j + 1))
    {
        f(grid, n, i, j + 1);
    }
    // up
    if (canWeGo(grid, n, i - 1, j))
    {
        f(grid, n, i - 1, j);
    }
    // down
    if (canWeGo(grid, n, i + 1, j))
    {
        f(grid, n, i + 1, j);
    }

    grid[i][j] = 0; // backtracking
}

int main()
{

    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0, 0, 0},
    };
    int n = grid.size();
    f(grid, n, 0, 0);

    cout << ans;
}