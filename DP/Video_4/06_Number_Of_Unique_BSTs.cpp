// leetcode 96

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    // =====================================================
    // APPROACH 1: TOP-DOWN DP (RECURSION + MEMOIZATION)
    // =====================================================

    vector<int> dp1;

    int f(int n) {

       
        // Exactly one way to construct an empty BST.
        if (n == 0)
            return 1;

        // One node -> 1 BST
        // Two nodes -> 2 BSTs
        if (n <= 2)
            return n;

       
        if (dp1[n] != -1)
            return dp1[n];

        int ans = 0;

        // Consider every node k as the root.
        for (int k = 1; k <= n; k++) {

            // Left subtree contains k-1 nodes.
            int left = f(k - 1);

            // Right subtree contains n-k nodes.
            int right = f(n - k);

            // Every left subtree can combine with
            // every right subtree.
            ans += left * right;
        }

        // Store and return the calculated answer.
        return dp1[n] = ans;
    }

    // APPROACH 2: BOTTOM-UP DP (TABULATION)
    

    int g(int n) {

        // dp[i] = Number of unique BSTs possible
        // using i distinct nodes.
        vector<int> dp(n + 1, 0);

        // Base Cases:
        dp[0] = 1;  // One empty BST.
        
        if (n >= 1)
            dp[1] = 1;  // One node -> 1 BST.

        if (n >= 2)
            dp[2] = 2;  // Two nodes -> 2 BSTs.

        // Calculate answers for 3 to n nodes.
        for (int i = 3; i <= n; i++) {

            // Try every possible node k as root.
            for (int k = 1; k <= i; k++) {

                // Left subtree has k-1 nodes.
                // Right subtree has i-k nodes.

                int left = dp[k - 1];
                int right = dp[i - k];

                // Add all possible combinations
                // of left and right subtrees.
                dp[i] += left * right;
            }
        }

        // Return the number of unique BSTs with n nodes.
        return dp[n];
    }


    int numTrees(int n) {

        dp1.assign(n + 1, -1);

        
        return g(n);
    }
};


// =====================================================
// COMPLEXITY ANALYSIS
// =====================================================

// TOP-DOWN DP:
// Time Complexity:  O(n^2)
// Space Complexity: O(n) for DP + recursion stack.

// BOTTOM-UP DP:
// Time Complexity:  O(n^2)
// Space Complexity: O(n) for DP array.
