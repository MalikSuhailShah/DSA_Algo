#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int f(vector<vector<int>> &arr, int n, int i)
{
    if (n == 0)
        return arr[0][i];

    if (dp[n][i] != -1)
        return dp[n][i];

    int ans = 0;
    if (i == 0)
        ans = arr[n][i] + max(f(arr, n - 1, 1), f(arr, n - 1, 2));
    else if (i == 1)
        ans = arr[n][i] + max(f(arr, n - 1, 0), f(arr, n - 1, 2));
    else
        ans = arr[n][i] + max(f(arr, n - 1, 0), f(arr, n - 1, 1));

    return dp[n][i] = ans;
}

int main()
{

    int n;
    cout << "Enter the Days for the vacations: " << endl;
    cin >> n;


    vector<vector<int>> arr(n + 1, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(100005, vector<int>(3, 0));
    // dp[n][i] = max points upto day n if ith activity is selected on nth day
    dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = arr[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = arr[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = arr[i][2] + max(dp[i - 1][1], dp[i - 1][0]);
    }

    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}