// LeetCode-56 => https://leetcode.com/problems/merge-intervals/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//start time sorting based
class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> & b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // performing sorintg based on start time
        sort(intervals.begin(), intervals.end(),cmp);

        vector<vector<int>> res; //=>2D vector
        res.push_back(intervals[0]);

        // approaching from foraward direction

        for(int i=1;i<n;i++){
            vector<int> curr=intervals[i];//curr is 1D vector
            int x=res.size();
            if(res[x-1][1]>=curr[0]){
                res[x-1][0]=min(res[x-1][0],curr[0]);
                res[x-1][1]=max(res[x-1][1],curr[1]);
            }
            else {
                res.push_back(curr);
            }
        }

        return res;
        
        
    }
};
int main (){

}