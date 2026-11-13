// LeetCode - 746. Min Cost Climbing Stairs => https://leetcode.com/problems/min-cost-climbing-stairs/description/

#include<iostream>
#include<vector>
using namespace std;

// Bottom Up recursion solution  (gives TLE without DP)
class Solution {
public:

    int helper(vector<int> & cost, int i){
        
        if(i>=cost.size()) return 0;
       
         return cost[i] + min(helper(cost,i+1), helper(cost, i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min( helper(cost,0),helper(cost,1));
        
    }
};


// Top Down Recursion Solution  (gives TLE without DP)

class Solution0 {
public:

    int helper(vector<int> & cost, int i){
        if(i<=1) return cost[i];
        return cost[i]+min(helper(cost,i-1),helper(cost, i-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return min(helper(cost,n-1), helper(cost,n-2));
        
    }
};


// Top Down Approach with DP [Recursion + Memoization]
class Solution1 {
public:

    int helper(vector<int> & cost, int i, vector<int> & dp){
        if(i<=1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(helper(cost,i-1, dp),helper(cost, i-2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(helper(cost,n-1,dp), helper(cost,n-2,dp));
        
    }
};

// Bottom up DP approach [ Recursion + Memoization]

class Solution2 {
public:

    int helper(vector<int> & cost, int i, vector<int> & dp){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(helper(cost,i+1, dp),helper(cost, i+2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(helper(cost,0,dp), helper(cost,1,dp));
        
    }
};


// DP [Tabulation Method]

class Solution3 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        for (int i = 2; i < n; i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }

        return min(cost[n - 1], cost[n - 2]);
    }
};

int main (){

}