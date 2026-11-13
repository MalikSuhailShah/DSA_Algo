#include<iostream>
#include<vector>
using namespace std;

// version 1 using recursion only {SC=O(n), TC=O(2^n)}
class Solution1 {
public:
    int fib(int n) {
      if(n<=1) return n;
      return fib(n-1)+fib(n-2);
        
    }
};


// version 2 using dp (recursion + memoization) [Top Down DP] {SC=O(n)(array)+ O(n)(call stack), TC=O(2*n)==O(n)}
class Solution2 {
public:

    int fibo(int n , vector<int> & dp){
        if(n<=1) return n;
        if(dp[n]==-1) dp[n]=fibo(n-1,dp) + fibo(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
       vector<int> dp(n+1,-1);
       return fibo(n,dp);
        
    }
};

// version 3 [Tabulation , Bottom Up, Iterative DP] Method   {SC=O(n)(array), TC=O(n))}

class Solution3 {
public:   
    int fib(int n) {
                        if(n<=1) return n;
                        vector<int> dp(n+1);
                        dp[0]=0;
                        dp[1]=1;
                        for(int i=2;i<=n;i++){
                            dp[i]=dp[i-1]+dp[i-2];
                        }
                        return dp[n];       
                   }
};

int main (){

}