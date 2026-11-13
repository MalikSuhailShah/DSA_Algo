// gfg => https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
  public:
  
    static bool cmp(vector<int> &a , vector<int> & b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<vector<int>> v;

        for(int i=0;i<start.size();i++){
            v.push_back({start[i], finish[i]});
        }  

        //end sorting
        sort(v.begin(),v.end(),cmp);
        
        int lastEnd=v[0][1];
        int count=0;
        for(int i=1;i<v.size();i++){
            if(v[i][0]<=lastEnd){
                count++;
                    
            }
            else lastEnd=v[i][1];
        }
        
        return v.size()-count;
        
    }
};
int main (){

}