#include <iostream>
#include <climits>
#include<vector>

using namespace std;


// recursive soln
int helper(int n)
{

    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;

    

    int dec = helper(n - 1);
    int dev2= (n%2==0)?helper(n/2):INT_MAX;
    int dev3 = (n%3==0)?helper(n/3):INT_MAX;

    return 1 + min(dec, min(dev2, dev3));
}

// recursive + memoization soln
int helper1(int n, vector<int> & dp)
{

    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;

    if(dp[n]!=-1) return dp[n];

    int dec = helper1(n - 1,dp);
    int dev2= (n%2==0)?helper1(n/2,dp):INT_MAX;
    int dev3 = (n%3==0)?helper1(n/3,dp):INT_MAX;

    return dp[n]=1 + min(dec, min(dev2, dev3));
}

// DP soln with tabulation 

int helper2(vector<int>& dp, int n){
   dp[1]=0;
   dp[2]=1;
   dp[3]=1;

   for(int i=4;i<=n;i++){
    int dec=dp[i-1];
    int div2=(i%2==0)?dp[i/2]:INT_MAX;
    int div3=(i%3==0)?dp[i/3]:INT_MAX;

    dp[i]=1+min(dec,min(div2,div3));
   }

   return dp[n];

}

int main()
{
    int n;
    cout << "Enter the value of n:" << endl;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << helper2(dp,n) << endl;
}