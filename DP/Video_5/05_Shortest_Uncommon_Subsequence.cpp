
#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;


class Solution {
  public:
    vector<vector<int>> dp;
    int f(string &s, string &t, int i, int j){
        
        if(i==s.length()) return INT_MAX;
        if(j >= t.length()) return 1; // atleast one char of string s remains 
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        int k = j;
        while(k<t.size() and t[k]!=s[i]) k++;
        
        if(k==t.length()) return 1;
        
        int skip = f(s,t,i+1,j);
        int take = f(s,t,i+1,k+1);
        if(take!=INT_MAX) take++;
        
        return dp[i][j] = min(take, skip);
        
    }
  
    int shortestUnSub(string &s, string &t) {
        // code here
        dp.resize(1005, vector<int> (1005, -1));
        return f(s,t,0,0)==INT_MAX?-1:f(s,t,0,0);
    }
};

int main (){
  Solution s;

    string a = "babab";
    string b = "babba";

    cout << s.shortestUnSub(a, b) << endl;

    return 0;
}