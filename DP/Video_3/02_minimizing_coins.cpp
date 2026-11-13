#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// top down approach

int f(vector<int> &c, int num, vector<int> &dp)
{
    if (num == 0)
        return 0;
    if (dp[num] != -2)
        return dp[num];

    int result = INT_MAX;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] > num)
            continue;
        result = min(result, f(c, num - c[i], dp));
    }
    if (result == INT_MAX)
        return dp[num] = INT_MAX;
    return dp[num] = 1 + result;
}

// Bottom up Approach

int f2(int num, vector<int> &coins)
{
    vector<int> dp(num + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < (int)coins.size(); j++)
        {
            if (i - coins[j] > 0 && dp[i] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    return dp[num];
}

int main()
{

    int n, x;
    cin >> n >> x;

    vector<int> coins;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        coins.push_back(num);
    }
    vector<int> dp(x + 1, -2);
    int ans = f2(x, coins);

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
}