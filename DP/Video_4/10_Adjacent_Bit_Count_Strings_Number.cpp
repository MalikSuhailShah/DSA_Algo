/*Given two integers n and k, count the number of binary strings of length n(basically think like  we have to from all possible string , we have not given any string) that contain exactly k adjacent pairs of 1s.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// fix the fisrt char of every string for every subproblem
int f(int n, int k, int previousChar , vector<vector<vector<int>>> &dp) // => count of strings of length n ,having adjacent bit count k and previousChar  character "previousChar "
{
    if (n == 0)
        return 0;
    if (n == 1)
    {
        if(k==0) return 1;
        else return 0;
    }
    if (dp[n][k][previousChar ] != -1)
        return dp[n][k][previousChar ];

    int ans = 0;

    if (previousChar  == 0)
        ans = f(n - 1, k, 0, dp) + f(n - 1, k, 1, dp); // we have used one char from n, so remaining char is n-1
    else
        ans = f(n - 1, k, 0, dp) + f(n - 1, k - 1, 1, dp);

    return dp[n][k][previousChar ] = ans;
}

int main()
{

    int t;
    cin>>t;
    while(t--){
        int num,n, k;

        cin>>num>>n>>k;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int> ( 2, -1)));
        int ans = f(n,k,0 , dp) + f(n,k,1,dp); // we have already fix the first char

        cout<<endl<<endl;

        cout<<num<<" "<<ans;
        
    }
}