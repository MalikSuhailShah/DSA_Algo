//https://leetcode.com/problems/max-consecutive-ones-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int  n = nums.size();
        int i=0, j=0, flips=0, len=INT_MIN, maxLen=INT_MIN;

        while(j<n){
           if(nums[j]==1) j++;
           else if(flips < k){
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
        return maxLen;
        
    }
};

int main (){
    
}