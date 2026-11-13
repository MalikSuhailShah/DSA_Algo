// Leetcode-688

#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

// double dp[30][30][105];

class Solution {
public:
    vector<vector<double>> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    double dp[30][30][105];
    double f(int n, int k, int row, int col) {
        if (row < 0 or row >= n or col < 0 or col >= n)
            return 0;
        if (k == 0)
            return 1;
        if (dp[row][col][k] > -0.9)
            return dp[row][col][k];

        double ans = 0;

        for (int i = 0; i < moves.size(); i++) {
            ans += f(n, k - 1, row + moves[i][0], col + moves[i][1]) * 0.125;
        }
        return dp[row][col][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, -1, sizeof dp);

        return f(n, k, row, column);
    }
};
int main()
{

    
}