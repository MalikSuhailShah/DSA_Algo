#include<iostream>
#include<vector>
#include<climits>
#define mod 1000000007
using namespace std;


//top down approach
int f(int x, vector<long long> & dp){
    if(x==0) return 1;

    if(dp[x]!=-1) return dp[x];

    long long res = 0;
    for(int i=1;i<=6;i++){
        if(x-i<0){
           break;
        }
         res = (res + f(x-i, dp))%mod;
    }

    return dp[x]=res%mod ;
}

// bottom up approach 
int f2(int x){
    vector<int> dp(x+1,-1);

    dp[0]=1;

    for(int i=1;i<=x;i++){
        long long sum=0;

        for(int j=1;j<=6;j++){
            if(i-j<0) break;
            sum = (sum + dp[i-j])%mod;
        }
        dp[i]=sum%mod;
    }
    return dp[x];
}


int main (){

    int n;
    cin>>n;
    vector<long long> dp(n+1,-1);
    cout<<f2(n);
    return 0;

}