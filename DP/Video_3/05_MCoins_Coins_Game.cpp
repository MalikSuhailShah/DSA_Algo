/*Asen and Boyan play a coin-removal game with N coins.
- They can remove 1, K, or L coins per turn.
- Asen plays first, then Boyan, alternating turns.
- The player who removes the last coin wins.
- Both players play optimally.
Task: For each given value of N, determine whether Asen (first player) can guarantee a win or Boyan will win.

Input: K, L, M (number of games), followed by M values of N.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

bool solve(int n, int k, int l)
{

    // Base case
    if (n == 0)
    {
        return false;
    }

    // If already calculated
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Case 1: Remove 1 coin
    if (!solve(n - 1, k, l))
    {
        return dp[n] = true;
    }

    // Case 2: Remove K coins
    if (n >= k && !solve(n - k, k, l))
    {
        return dp[n] = true;
    }

    // Case 3: Remove L coins
    if (n >= l && !solve(n - l, k, l))
    {
        return dp[n] = true;
    }

    // All moves lead to winning states
    return dp[n] = false;
}

int main()
{
    int k, l, m; // m = no.of games

    cout << "Enter the value of k , l , m :" << endl;
    cin >> k >> l >> m;

    vector<int> queries(m);
    int maxValueOfN = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i];
        maxValueOfN = max(maxValueOfN, queries[i]);
    }

    dp.resize(maxValueOfN + 1, 0);
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        // Remove 1 coin
        int one_coin = dp[i - 1];

        // remove k coin
        int K_coin = (i >= k) ? dp[i - k] : 1; // we are using 1 because we dont want other possibilities to get effected by this move when this move is not possible

        // remove l coin
        int L_coin = (i >= l) ? dp[i - l] : 1; // we are using 1 because we dont want other possibilities to get effected by this move when this move is not possible

        dp[i] = not(one_coin and K_coin and L_coin);
    }

    for (int i = 0; i < m; i++)
    {
        if (dp[queries[i]])
            cout << "A";
        else
            cout << "B";
        cout << "\n";
    }
}