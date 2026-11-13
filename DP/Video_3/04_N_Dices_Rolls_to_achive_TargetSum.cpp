// LeetCode - 1155 Number of Dice Rolls With Target Sum,, =>https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    #define mod 1000000007
    #define ll long long int

    //Top Down Approach
    int f(int n, int k , int  t, vector<vector<ll>> & dp){
        if(n==0 && t==0) return 1;
        if(n==0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];
        ll sum=0;
        for(int v=1;v<=k;v++){
            if(t-v<0) continue;
            sum =( sum%mod + f(n-1,k,t-v,dp)%mod)%mod;
        }
        return dp[n][t]=sum;
    }

    //Bottom Up Approach

    int fBU(int n, int k, int target){
        vector<vector<ll>> dp(n+1,vector<ll> (target+1, 0));

        dp[0][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int sum=0;
                for(int v=1;v<=k;v++){
                    if(j-v<0) continue;
                    sum = (sum + dp[i-1][j-v])%mod;
                }

                dp[i][j]=sum;
            }
        }

        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
      vector<vector<ll>> dp(n+1, vector<ll> (target+1,-1));

      return fBU(n,k,target);

        
    }
};

int main (){

}