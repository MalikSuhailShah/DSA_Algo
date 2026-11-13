// LeetCode-63 => https://leetcode.com/problems/unique-paths-ii/

#include<iostream>
#include<vector>
using namespace std;

// recursive solution [gives TLE]
class Solution1 {
public:
    int helper(vector<vector<int>> & arr, int m , int n){
      
        if(m<0 || n<0) return 0;

        
        if(arr[m][n]==1) return 0;

         if(m==0 && n==0) return 1;
        int rightways=helper(arr,m-1,n);
        int downways= helper(arr,m,n-1);


        return rightways+downways;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m= arr.size();
        int n=arr[0].size();

        return helper(arr,m-1,n-1);
        
    }
};

// recursion + memoization solution

class Solution2 {
public:
    int helper(vector<vector<int>>& arr, int m, int n,vector<vector<int>> & dp) {

        if (m < 0 || n < 0)
            return 0;
        if (arr[m][n] == 1)
            return 0;
        if (m == 0 && n == 0)
            return 1;
        if (dp[m][n] != -1)
            return dp[m][n];

        int rightways = helper(arr, m - 1, n , dp);
        int downways = helper(arr, m, n - 1 , dp);

        return dp[m][n] = rightways + downways;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(arr, m - 1, n - 1, dp);
    }
};


// Tabulation DP solution

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        if(arr[0][0]==1) return 0;

        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) dp[i][j]=0;
                else {
                    if(i>0) dp[i][j]+=dp[i-1][j];
                    if(j>0) dp[i][j]+=dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
        
    }
};

int main (){

}