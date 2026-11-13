#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

vector<vector<vector<int>>> dp;// 3D dp 

ll f(int *a, int *b,int m, int n,  int i, int j, int k){

    // base case

    if(i==m or j==n) return 0;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    // computation

    ll res =0;
    if(a[i]==b[j])  res = 1 + f(a,b,m,n,i+1,j+1,k);
    else{
        if(k>0){
            res = 1 + f(a,b,m,n,i+1,j+1,k-1);
        }
        res = max (res, f(a,b,m,n,i+1,j,k));
        res = max (res, f(a,b,m,n,i,j+1,k));
    }

    dp[i][j][k] = res;
    return dp[i][j][k];

}
int main (){

}