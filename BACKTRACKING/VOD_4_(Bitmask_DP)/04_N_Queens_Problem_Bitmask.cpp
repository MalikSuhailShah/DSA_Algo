#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> mat;
vector<vector<string>> result; // it stores multiple solutions
int row_mask = 0;
int col_mask = 0;
int right_mask = 0;
int left_mask = 0;

bool canPlace(int row, int col, int n)
{
    bool row_available = (((1 << (row )) & row_mask) == 0);
    bool col_available = (((1 << (col )) & col_mask) == 0);

    // for right diagonal
    int m = row + col;
    bool right_available = ((1 << (m )) & right_mask) == 0;

    // left diagonal
    int p = (n - 1) + row - col;
    bool left_available = ((1 << (p )) & left_mask) == 0;

    if (row_available and col_available and right_available and left_available)
        return true;

    return false;
}

void updateMask(int row, int col, int n)
{
    // for row update
    row_mask = row_mask | (1 << (row));
    // for col update
    col_mask = col_mask | (1 << (col));

    // for left diagonal update
    int p = n - 1 + row - col;
    left_mask = left_mask | (1 << (p));
    // for left diagonal update
    int m = row + col;
    right_mask = right_mask | (1 << (m));
}

void backTrackMask(int row, int col, int n)
{
    // for row update
    row_mask = row_mask ^ (1 << (row));
    // for col update
    col_mask = col_mask ^ (1 << (col));

    // for left diagonal update
    int p = n - 1 + row - col;
    left_mask = left_mask ^ (1 << (p));
    // for left diagonal update
    int m = row + col;
    right_mask = right_mask ^ (1 << (m));
}

void f(int row, int n)
{
    if (row == n)
    { // means we have reached one solution to place the queens on the board
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string ans = "";
            for (int j = 0; j < mat[i].size(); j++)
            {
                ans += mat[i][j];
            }
            temp.push_back(ans);
        }

        result.push_back(temp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (canPlace(row, i, n))
        {
            updateMask(row, i, n);
            mat[row][i] = 'Q';
            f(row + 1, n);
            mat[row][i] = '.';
            backTrackMask(row, i, n);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    result.clear();

    mat.clear();
    mat.resize(n, vector<char>(n, '.'));
  
    f(0, n);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << "\n";
        }
        cout << "\n\n";
    }
}