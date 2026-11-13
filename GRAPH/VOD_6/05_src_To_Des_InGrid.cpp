/*
Given a grid of n*m size, every cell of the grid is marked with one of the characters 'L', 'R', 'U', or 'D'.
The character on a cell denotes the direction in which you can move from that cell:
- 'L' — Left
- 'R' — Right
- 'U' — Up
- 'D' — Down
You can move from cell [0,0] to cell [n-1,m-1]. Check if you can reach [n-1,m-1] starting from [0,0].
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> v(rows, vector<char>(cols, ' '));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> v[i][j];
        }
    }

    queue<pair<int, int>> qu;
    set<pair<int, int>> visited;

    qu.push({0, 0});
    visited.insert({0, 0});

    int count = 0;

    bool reached = false;

    while (qu.size())
    {
        auto curr = qu.front();
        qu.pop();

        int r = curr.first, c = curr.second;

        if (count == rows * cols)
        {
            break;
        }

        if (r == rows - 1 && c == cols - 1)
        {
            reached = true;
            break;
        }
        count++;

        if (v[r][c] == 'U')
        {
            if (r - 1 >= 0 && not visited.count({r - 1, c}))
            {
                qu.push({r - 1, c});
                visited.insert({r - 1, c});
            }
        }
        if (v[r][c] == 'D')
        {
            if (r + 1 < rows && not visited.count({r + 1, c}))
            {
                qu.push({r + 1, c});
                visited.insert({r + 1, c});
            }
        }
        if (v[r][c] == 'L')
        {
            if (c - 1 >= 0 && not visited.count({r, c - 1}))
            {
                qu.push({r, c - 1});
                visited.insert({r, c - 1});
            }
        }
        if (v[r][c] == 'R')
        {
            if (c + 1 < cols && not visited.count({r, c + 1}))
            {
                qu.push({r, c + 1});
                visited.insert({r, c + 1});
            }
        }
    }

    if (reached)
        cout << "Can reach destination" << endl;
    else
        cout << "Can't reach destination";
}