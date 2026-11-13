// at coder educational dp contest  :- https://atcoder.jp/contests/dp/tasks/dp_u

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define ll long long

// dp[mask] = maximum score obtainable by partitioning
// all people represented by 'mask' into groups.
//
// sum[mask] = score obtained if all people represented
// by 'mask' are placed together in ONE group.
//
// N <= 16, so there are at most 2^16 possible masks.
vector<ll> dp(1 << 16, LLONG_MIN);
vector<ll> sum(1 << 16, 0);


// STEP 1: Calculate the score of one group.
//
// 'mask' tells us which people belong to this group.
// If bits i and j are both set, people i and j are
// in the same group, so add compat[i][j].
ll calc(vector<vector<ll>> &compat, int mask, int n)
{
    ll ans = 0;

    // Consider every pair of distinct people.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Check whether person i belongs to this group.
            bool hasI = (mask & (1 << i)) != 0;

            // Check whether person j belongs to this group.
            bool hasJ = (mask & (1 << j)) != 0;

            // If both are in the group, add their pair score.
            if (hasI && hasJ)
            {
                ans += compat[i][j];
            }
        }
    }

    return ans;
}


// STEP 2: Precompute the score of every possible group.
//
// Instead of calculating a group's score repeatedly,
// calculate it once and store it in sum[mask].
void precompute(vector<vector<ll>> &compat, int n)
{
    int totalMasks = 1 << n;

    for (int mask = 1; mask < totalMasks; mask++)
    {
        sum[mask] = calc(compat, mask, n);
    }
}


// STEP 3: Find the maximum score for the people in 'mask'.
//
// Idea:
// 1. Choose a nonempty group g from the available people.
// 2. Its score is sum[g].
// 3. The remaining people are represented by mask ^ g.
// 4. Recursively find the best score for those people.
// 5. Try every possible group g and take the maximum.
ll f(int mask)
{
    // Base case: no people remain, so no more score can be added.
    if (mask == 0)
    {
        return 0;
    }

    // If we have already solved this mask, reuse its answer.
    if (dp[mask] != LLONG_MIN)
    {
        return dp[mask];
    }

    // We are maximizing, so begin with the smallest possible value.
    ll ans = LLONG_MIN;

    // Enumerate every NONEMPTY submask g of mask.
    //
    // Example: if mask = 1011, possible g values are:
    // 1011, 1010, 1001, 1000, 0011, 0010, 0001.
    //
    // Each g represents a possible first group.
    for (int g = mask; g != 0; g = ((g - 1) & mask))
    {
        // mask ^ g removes the people assigned to group g.
        //
        // Candidate answer =  score of chosen group + best score for remaining people.
        ll candidate_answer = sum[g] + f(mask ^ g);

        // Keep the best partition found so far.
        ans = max(ans, candidate_answer);
    }

    // Memoize the answer so we never solve this mask again.
    return dp[mask] = ans;
}


int main()
{
    int n;
    cin >> n;

    // compat[i][j] is the score contributed by pair (i, j).
    // People are numbered from 0 to n-1.
    vector<vector<ll>> compat(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> compat[i][j];
        }
    }

    // Calculate scores for all possible groups.
    precompute(compat, n);

    // (1 << n) - 1 has its lowest n bits set to 1.
    // It represents the mask containing EVERY person.
    int allPeople = (1 << n) - 1;

    // Find the best way to partition everyone into groups.
    cout << f(allPeople) << '\n';

    return 0;
}
