// Leet Code-198

#include<iostream>
#include<vector>
using namespace std;

// recursion approach 
class Solution0 {
public:

    int RecSoln(vector<int> & arr, int idx){
        int n=arr.size();

        if(idx>=n) return 0;
        if(idx==n-1) return arr[n-1];
     

        int rob=arr[idx] +RecSoln(arr, idx+2);
        int skip=RecSoln(arr,idx+1);      
        return  max(rob,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        return RecSoln(nums,0);
    }
};


// top-down approach soln
class Solution1 {
public:

    int DPRecSoln(vector<int> & arr, int idx, vector<int>& dp){
        int n=arr.size();

        if(idx>=n) return 0;
        if(idx==n-1) return arr[n-1];
      
       if(dp[idx]!=-1) return dp[idx];

        int rob=arr[idx] + DPRecSoln(arr, idx+2,dp);
        int skip= DPRecSoln(arr,idx+1,dp);      
        return dp[idx] = max(rob,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return  DPRecSoln(nums,0,dp);
    }
};

// Bottom up [Tabulation DP Approach]
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[n-1]=nums[n-1];
        dp[n-2]= max(nums[n-2],nums[n-1]);
   
        for(int i=n-3;i>=0;i--){
            dp[i]=max(0 + dp[i+1], nums[i] + dp[i+2]);
        }

        return dp[0];
        
    }
};

int main (){

}