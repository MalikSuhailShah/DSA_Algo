// LeetCode - 452  => https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// In this we stores  the common positions for all the ballons so that arrows can be shot only at those positions only
class Solution {
public:

    static bool cmp(vector<int> & a, vector<int> & b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {

       int n=points.size();
        // performing sorintg based on end time
        sort(points.begin(), points.end(),cmp);

        vector<vector<int>> res; //=>2D vector
        res.push_back(points[n-1]);

        // approaching from backword direction

        for(int i=n-2;i>=0;i--){
            vector<int> curr=points[i];//curr is 1D vector
            int x=res.size();
            if(res[x-1][0]<=curr[1]){
                res[x-1][0]=max(res[x-1][0],curr[0]);
                res[x-1][1]=min(res[x-1][1],curr[1]);
            }
            else {
                res.push_back(curr);
            }
        }

        return res.size();
        
    }
};

int main (){

}