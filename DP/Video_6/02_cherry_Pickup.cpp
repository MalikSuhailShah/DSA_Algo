// leetcode 741

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#define ll long long int

using namespace std;

class Solution {
public:
    ll dp[55][55][55];
    vector<vector<int>> nums;
    int rows, cols;
    ll f(int i, int j, int x, int y) {
        if (i >= rows or j >= cols or x >= rows or y >= cols or nums[i][j] == -1 or
            nums[x][y] == -1)
            return LLONG_MIN;
        if (i == rows-1 and j == cols-1)
            return nums[i][j] == 1;

        if (dp[i][j][x] != -1)
            return dp[i][j][x];

        ll ans = LLONG_MIN;

        ans = max(ans, f(i + 1, j, x + 1, y));
        ans = max(ans, f(i + 1, j, x, y + 1));
        ans = max(ans, f(i, j + 1, x + 1, y));
        ans = max(ans, f(i, j + 1, x, y + 1));

        if(ans==LLONG_MIN) return dp[i][j][x] =  LLONG_MIN;
        ans += nums[i][j] == 1;
        ans += nums[x][y] == 1;

        if (nums[i][j] == 1 and i == x and j == y)
            ans--;

        return dp[i][j][x] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        nums = grid, rows = grid.size(), cols = grid[0].size();
        memset(dp, -1, sizeof dp);

        ll ans = f(0, 0, 0, 0);
        return ans ==LLONG_MIN?0:ans;
    }
};