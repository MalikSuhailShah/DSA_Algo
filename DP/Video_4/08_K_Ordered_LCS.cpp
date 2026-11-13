#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int KOrderedLCS(vector<int> &a, vector<int> &b, int i, int j, int k, vector<vector<vector<int>>> &dp)
{
    if (i == a.size() || j == b.size())
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int res = 0;

    if (a[i] == b[j])
        res = 1 + KOrderedLCS(a, b, i + 1, j + 1, k, dp);
    else
    {
        if (k > 0)
        {
            res = 1 + KOrderedLCS(a, b, i + 1, j + 1, k - 1, dp);
        }
        res = max(res, KOrderedLCS(a, b, i + 1, j, k, dp));
        res = max(res, KOrderedLCS(a, b, i, j + 1, k, dp));
    }

    return dp[i][j][k] = res;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> seq1(n), seq2(m);

    for (int i = 0; i < n; i++)
        cin >> seq1[i];
    for (int i = 0; i < m; i++)
        cin >> seq2[i];

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (k+1,-1)));
    KOrderedLCS(seq1,seq2,0,0,k,dp);
}