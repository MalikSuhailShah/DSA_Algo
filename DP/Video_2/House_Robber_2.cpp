// leetCode - 213 => https://leetcode.com/problems/house-robber-ii/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    // top down solution
    int RecSoln(vector<int> & arr, int i, int j,vector<int> & dp){
       
        if(i>j) return 0;
        if(dp[i]!=-1) return dp[i];

        int rob = arr[i] + RecSoln(arr, i+2, j,dp);
        int skip = RecSoln(arr, i+1, j,dp);

        return  dp[i] = max(rob, skip);

    }

    // bottom up solution
    int BottomUp(vector<int> & arr, int i, int j){
        int n = arr.size();
        vector<int> dp(n+2, 0);
        
        for(int p=j;p>=i;p--){
            dp[p] = max(dp[p+2]+ arr[p], dp[p+1]);
        }

        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        //int right = RecSoln(nums, 0,n-2,dp);
        vector<int> dp1(n+1 , -1);
        //int left = RecSoln(nums,1,n-1,dp1);

        //return max(right, left);

       int right = BottomUp(nums,0,n-2);
       int left = BottomUp(nums,1,n-1);

       return max(right, left);
    }
};