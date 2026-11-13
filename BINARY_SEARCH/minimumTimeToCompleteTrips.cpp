//https://leetcode.com/problems/minimum-time-to-complete-trips/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(vector<int>& time, long long currTime, long long totalTrips)
    {// currTime = time to complete all the trips
        long long trips = 0;

        for(int t : time)
        {
            trips += currTime / t;

            // Optional optimization: this can also used outside of loop
            if(trips >= totalTrips)
                return true;
        }

        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips)
    {
        long long minTime = INT_MAX;

        for(int t : time)
        {
            minTime = min(minTime, (long long)t);
        }

        long long lo = 1;
        long long hi = minTime * totalTrips;

        while(lo <= hi)
        {
            long long mid = lo + (hi - lo) / 2;

            if(check(time, mid, totalTrips))
            {
                // mid time is sufficient.
                // Try to find a smaller time.
                hi = mid - 1;
            }
            else
            {
                // Not enough trips.
                // Need more time.
                lo = mid + 1;
            }
        }

        return lo;
    }
};