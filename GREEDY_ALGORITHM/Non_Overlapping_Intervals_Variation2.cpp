// LeetCode-453 => https://leetcode.com/problems/non-overlapping-intervals/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

    static bool cmp(vector<int> & a, vector<int> & b){
        if(a[1] == b[1])
        return a[0] < b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();
        // sorting based on end time
        sort(intervals.begin(), intervals.end(), cmp);

        int lastEnd=intervals[0][1];
        int ans=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<lastEnd)  ans++;
            else lastEnd=intervals[i][1];
        }

        return ans;
        
    }
};
int main (){

}