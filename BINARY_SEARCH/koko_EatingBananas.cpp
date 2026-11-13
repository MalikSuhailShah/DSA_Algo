//https://leetcode.com/problems/koko-eating-bananas/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(vector<int>  piles, int currSpeed,int h ){
        int n = piles.size();
        long long hoursNeeded = 0;
        int i=0;
        while(i<n){
          if(currSpeed>piles[i]) hoursNeeded++;
          else if(piles[i]%currSpeed==0){
            hoursNeeded += (long long )(piles[i]/currSpeed);
          }
          else {
            hoursNeeded += (long long )(piles[i]/currSpeed) +1;
          }
          i++;
        }

        return hoursNeeded <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n =piles.size();

        int maxSpeed = INT_MIN;

        for(int i=0;i<n;i++) maxSpeed = max(maxSpeed, piles[i]);

        if(n==h) return maxSpeed;

        int lo=1, hi = maxSpeed;
        int minSpeed = -1;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            if(check(piles,mid,h)){
                minSpeed = mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return minSpeed;
    }
};