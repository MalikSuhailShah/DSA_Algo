//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int  n = nums.size();
        int i=0, j=0, flips=0, len=INT_MIN, maxLen=INT_MIN;

        while(j<n){
           if(nums[j]==1) j++;
           else if(flips < 1){
            flips++;
            j++;
           }
           else{
            len = j-i;
            maxLen = max(maxLen, len);

            while(nums[i]==1) i++;
            i++;
            flips--; // if j++ is used in place of flips-- then also code will work finely
           }

          
        }
        len = j-i;
        maxLen = max(len, maxLen);
        return maxLen-1;
        
    }
};