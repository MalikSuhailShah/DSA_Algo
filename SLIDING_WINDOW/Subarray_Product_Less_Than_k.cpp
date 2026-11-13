//https://leetcode.com/problems/subarray-product-less-than-k/submissions/2125162283/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int n = nums.size();
        int i=0, count =0;
        long long product =1;
        for(int j=0;j<n;j++){
            product*=nums[j];

            while(product>=k && i<=j){
                product/=nums[i];
                i++;
            }

            count += j-i+1;
        }

        return count;
    }
};