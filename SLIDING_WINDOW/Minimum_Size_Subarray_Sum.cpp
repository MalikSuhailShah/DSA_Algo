//https://leetcode.com/problems/minimum-size-subarray-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int minLen = INT_MAX;
        int len =0;
        int i=0,j=0;
        int sum =0;

        while(j<n){
            sum += nums[j];

            while(sum >= target){// sum is already larger than the target so checking for the smaller length subarray
                len = j-i+1;
                minLen = min(minLen, len);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        
        if(minLen==INT_MAX) return 0;
        else return minLen;
    }
};

int main (){
    
}