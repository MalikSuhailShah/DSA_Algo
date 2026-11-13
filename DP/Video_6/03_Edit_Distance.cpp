// leetcode 72

#include<iostream>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    int dp[505][505];
    int f(string s1, string s2, int i, int j) {
        if (i >= s1.length())
            return s2.size()-j; // remaining string is considered only
        if (j >= s2.length())
            return s1.size()-i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        if (s1[i] == s2[j])
          return dp[i][j] = f(s1,s2,i+1,j+1);
        else {
            ans = min(ans, 1 + f(s1, s2, i + 1, j + 1));
            ans = min(ans, 1 + f(s1, s2, i + 1, j));
            ans = min(ans, 1 + f(s1, s2, i, j + 1));
        }

        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);

        int ans = f(word1, word2, 0, 0);

        return ans;
    }
};

int main (){

}