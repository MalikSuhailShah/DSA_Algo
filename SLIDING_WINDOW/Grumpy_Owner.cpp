//https://leetcode.com/problems/grumpy-bookstore-owner/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), k = minutes;

        int maxLoss = INT_MIN;
        int idx = 0;
        int prevLoss = 0;
        for (int i = 0; i < k; i++) {
            if (grumpy[i]) {
                prevLoss += customers[i];
            }
        }

        maxLoss = prevLoss;
        int i=1,j=k;
        while(j<n){
            int currWindowLoss = prevLoss + grumpy[j]*customers[j] - grumpy[i-1]*customers[i-1];

            if(maxLoss < currWindowLoss){
                idx =i;
                maxLoss = currWindowLoss;
            }

            prevLoss = currWindowLoss;

            i++;
            j++;
        }

        for(int i = idx;i<idx+k;i++) grumpy[i]=0;

        int sum=0;
        for(int i=0;i<n;i++){
           if(!grumpy[i]) sum+= customers[i];
        }

        return sum;
        
    }
};

int main (){
    
}