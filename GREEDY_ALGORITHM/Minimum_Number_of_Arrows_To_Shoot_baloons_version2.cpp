// LeetCode - 452  => https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// In this soln we want to shot at end of earlist finishing balloon so that chance to shoot other balloon with same shot increases

class Solution {
public:

    static bool cmp(vector<int> & a, vector<int> & b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();

        //sort with respect to the end
        sort(points.begin(), points.end(), cmp);

        int lastEnd=points[0][1];

        int ans=1;

        for(int i=1;i<n;i++){
            if(points[i][0]>lastEnd){// one arrow cant shot both ponits[i][0] and lastEnd
                ans++;
                lastEnd=points[i][1];
            }
        }

        return ans;
        
    }
};

int main (){

}