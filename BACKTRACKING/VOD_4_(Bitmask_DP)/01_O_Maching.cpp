// atcoder problem

#include <iostream>
#include <vector>
#include <cstring>
#define mod 1000000007
using namespace std;

int dp[22][1 << 21];

int f(int i, int mask, int n, vector<vector<int>> &comp)
{
    if (i == n + 1)
    {
        if (mask == 0)
            return 1;
        return 0;
    }
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int ans = 0;
    for (int w = 1; w <= n; w++)
    {
        bool available = ((1 << (w - 1) & mask) == 0) ? 0 : 1;
        if (available and comp[i][w])
            ans = (ans%mod + f(i + 1, mask ^ (1 << (w - 1)), n, comp)%mod)%mod;
    }

    return dp[i][mask] = ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> comp(n + 1, vector<int>(n + 1)); // considering 1-based indexing
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> comp[i][j];
        }
    }

    memset(dp, -1, sizeof dp);
    cout << f(1, (1 << n) - 1, n, comp);
}