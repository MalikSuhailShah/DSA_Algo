//LeetCode-56 => https://leetcode.com/problems/merge-intervals/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//sorting based on end time

class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> & b){
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // performing sorintg based on end time
        sort(intervals.begin(), intervals.end(),cmp);

        vector<vector<int>> res; //=>2D vector
        res.push_back(intervals[n-1]);

        // approaching from backword direction

        for(int i=n-2;i>=0;i--){

            vector<int> curr=intervals[i];//curr is 1D vector
            int x=res.size();
            
            if(res[x-1][0]<=curr[1]){
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