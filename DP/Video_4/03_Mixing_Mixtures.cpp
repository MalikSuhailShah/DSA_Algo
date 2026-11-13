/*Mixtures – Minimum Smoke (Interval DP)
Harry has n mixtures arranged in a row, each having a color from 0 to 99.

He can mix only two adjacent mixtures at a time.
- When mixtures of colors a and b are mixed, the resulting color is (a + b) % 100.
- The smoke generated is a * b.
The resulting mixture replaces the two original mixtures.

Task: Find the minimum total smoke generated when all n mixtures are merged into one.

Input: An array of n integers representing the colors of the mixtures.

Output: Minimum possible total smoke.*/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long int
using namespace std;

//dp pattern : continuous interval pattern
int s(vector<int> &arr, int m, int p)
{
    int sum = 0;
    for (int i = m; i <= p; i++)
        sum = (sum % 100 + arr[i] % 100) % 100;

    return sum;
}

// top down solution
vector<vector<int>> dp;
int f(vector<int> &arr, int i, int j)
{
    if (i == j) // single mixture do not evolve any gas
        return 0;
    if (i == j + 1)
        return dp[i][j] = arr[i] * arr[j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        ans = min(ans, f(arr, i, k) + f(arr, k + 1, j) + s(arr, i, k) * s(arr, k + 1, j));
    }

    return dp[i][j] = ans;
}

// bottom up solution

int fbu(vector<int> &cols)
{
    int n = cols.size();
    dp.clear();
    dp.resize(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            int ans = INT_MAX;
            for (int k = i; k < j; k++)
            {
                ans = min(ans, dp[i][k] + dp[k + 1][j] + s(cols, i, k) * s(cols, k + 1, j));
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][n - 1];
}

int main()
{

    int n;

    while (cin >> n)
    {
        vector<int> color;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            color.push_back(x);
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(n + 1, -1)); // anthor way to resize the array : memset(dp,-1,sizeof dp); => #include<cstring> include this header file

        // cout << f(color, 0, n - 1);
        cout << fbu(color);

        color.clear();
    }
}