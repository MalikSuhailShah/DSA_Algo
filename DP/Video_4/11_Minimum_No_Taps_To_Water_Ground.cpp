//leetcode 1326

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f( vector<int> ranges)
{
    int n = ranges.size()-1;
    vector<int> dp(n+1, INT_MAX);

    dp[0] = 0;

    for (int i = 0; i <= n; i++)
    {
        int start = max(0, i - ranges[i]);
        int end = min(n, i + ranges[i]);

        int ans = INT_MAX;

        for (int j = start; j <= end; j++)
        {
            ans = min(ans, dp[j]);
        }

        if (ans != INT_MAX)
            dp[end] = min(dp[end], ans + 1);
    }

    return dp[n]==INT_MAX?-1 :dp[n];
}

int main()
{

    int n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    vector<int> ranges(n+1);
    for(int i=0;i<=n;i++){
        cin>>ranges[i];
    }

    cout<<f(ranges);
}