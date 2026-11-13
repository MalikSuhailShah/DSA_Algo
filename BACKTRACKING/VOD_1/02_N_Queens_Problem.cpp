//leetcode 51

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> grid;
vector<vector<string>> result;

bool canPlaceQueen(int row, int col, int n)
{

    // column check
    for (int i = row - 1; i >= 0; i--)
    {
        if (grid[i][col] == 'Q')
            return false;
    }

    // right diagonal check

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (grid[i][j] == 'Q')
            return false;
    }

    // left diagonal check
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (grid[i][j] == 'Q')
            return false;
    }

    return true;
}

void f(int n, int row)
{
    if (n == row)
    {
        vector<string> temp;
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            string ans = "";
            for (int j = 0; j < n; j++)
            {
                ans += grid[i][j];
            }

            temp.push_back(ans);
        }

        result.push_back(temp);

        return;
    }

    for (int cols = 0; cols < n; cols++)
    {
        if (canPlaceQueen(row, cols, n))
        {
            grid[row][cols] = 'Q';
            f(n, row + 1);
            grid[row][cols] = '.';
        }
    }
}

vector<vector<string>> nQueen(int n)
{
    grid.clear();
    grid.resize(n, vector<char>(n, '.'));
    result.clear();
    f(n, 0);

    return result;
}

int main()
{

    vector<vector<string>> ans = nQueen(4);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"\n";
        }
        cout<<"\n\n";
    }
}