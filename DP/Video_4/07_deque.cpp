/*You are given an array of N integers. Two players, Taro and Jiro, play a game alternately, with Taro playing first.

Rules:
1. On each turn, a player must remove either the first or the last element of the array.
2. The player earns points equal to the value of the removed element.
3. The game continues until the array becomes empty.
x-taros score, y - jiros score
Objective:
- Taro wants to maximize the score difference \(X-Y\).
- Jiro wants to minimize the score difference \(X-Y\).
- Both players play optimally.
Find: The final value of \(X-Y\).*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#define ll long long int
using namespace std;

vector<vector<ll>> dp;

/* top down approach
ll f(int i, int j, vector<int> &arr)
{
    if (i == j)
        return arr[i];
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = max(arr[i] - f(i + 1, j, arr), arr[j] - f(i, j - 1, arr));
}*/

// Bottom up approach

ll fbu(vector<int> &arr)
{
    int n = arr.size();
    dp.resize(n + 5, vector<ll>(n + 5, 0));
    // base case
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
    }

    // computation
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i+len-1;
            dp[i][j] = max(arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]); 
        }
    }

    return dp[0][n-1];
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    dp.clear();
    dp.resize(n + 1, vector<ll>(n + 1, -1));

    cout << fbu( arr);
}