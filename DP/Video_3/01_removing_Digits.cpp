// from n to 1 via substracting digits 

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> get_digits(int n){
    vector<int> res;

    while(n>0){
        if(n%10!=0) res.push_back(n%10);
        n/=10;
      
    }

    return res;
}


// Top Down Approach

int helper(int n, vector<int> & dp){
    if(n==0) return 0;
    if(n<10) return 1;
    if(dp[n]!=-1) return dp[n];


    vector<int> d = get_digits(n);

    int result= INT_MAX;  
 
    for(int i=0;i<d.size();i++){
        result = min(result, helper((n - d[i]), dp));
    }
    
    return dp[n] = 1 + result;
}

//Bottom Up Approach

int f(int n){

    vector<int> dp(n+1);

    dp[0]=0;
    for(int i=1;i<=9;i++) dp[i]=1;

    for(int i=10;i<=n;i++){
        // for ith state we have to calculate the value of dp[i]

        vector<int> d=get_digits(i);

        int res =INT_MAX;

        for(int j=0;j<d.size();j++){
            res = min(res,dp[i-d[j]]);
        }
        dp[i]= 1+ res;
    }

    return dp[n];


}

int main (){
    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<f(n )<<endl;
  
}