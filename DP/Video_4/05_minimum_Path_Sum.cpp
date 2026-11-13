// leetcode 64

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// top down Approach

class Solution {
public:
    vector<vector<int>> dp;
    int m, n;
    int f(vector<vector<int>>& grid, int i, int j) {
        if (i == m - 1 and j == n - 1) {
            return grid[i][j];
        }
        if (i >= m or j >= n)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        int rightAns = f(grid, i, j + 1);
        int downAns = f(grid, i + 1, j);

        return dp[i][j] = grid[i][j] + min(rightAns, downAns);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        return f(grid, 0, 0);
    }
};


// bottom up
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, 0));

        dp[m-1][n-1] = grid[m-1][n-1];

        for(int i=m-2 ; i>=0 ; i--){
            dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
        }

        for(int j=n-2;j>=0;j--){
            dp[m-1][j] = grid[m-1][j] + dp[m-1][j+1];
        }

        for(int i=m-2;i>=0;i--){
            for(int j = n-2; j>=0;j--){
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }

        return dp[0][0];
        
    }
};

int main()
{

}