/*You are given an \(N \times N\) chessboard, initially empty. A knight is placed at the top-left corner of the board, at position \((0,0)\).

Your task is to find and print all possible Knight’s Tours starting from \((0,0)\).

A Knight’s Tour is a sequence of moves in which the knight visits every square of the chessboard exactly once.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> dx = {-1, -2, 1, 2, -1, -2, 1, 2};
vector<int> dy = {2, 1, 2, 1, -2, -1, -2, -1};

bool canVisit(vector<vector<int>> &grid, int r, int c)
{
    return r >= 0 and c >= 0 and c < grid.size() and r < grid.size() and grid[r][c] == 0;
}

void display(vector<vector<int>> &grid)
{
    int n = grid.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void f(int n, vector<vector<int>> &grid, int count, int r, int c)
{

    if (!canVisit(grid, r, c))
        return;

    grid[r][c] = count;

    if (count == n * n)
    {
        display(grid);
        grid[r][c] = 0;
        return;
    }

    for (int k = 0; k < 8; k++)
    {
        int nr = r + dx[k];
        int nc = c + dy[k];

        f(n, grid, count + 1, nr, nc);
    }

    grid[r][c] = 0;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    f(n, grid, 1, 0, 0);
}