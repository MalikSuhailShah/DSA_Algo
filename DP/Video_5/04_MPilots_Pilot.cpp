//SPOJ QUESTION-

#include <iostream>
#include <vector>
using namespace std;

// vector<vector<int>> dp(10005, vector<int> (10005, -1));

// int f(int cap[], int asst[], int i, int x, int n)
// {

//     if (i == n)
//         return 0;

//     if(dp[i][x]!=-1) return dp[i][x];

//     int ans=0;
//     if(x==0){
//         ans+=asst[i] + f(cap,asst,i+1,x+1,n);
//     }
//     else if(x==n-i){
//         ans+=cap[i] + f(cap,asst,i+1,x-1,n);
//     }
//     else{
//         ans+= min(asst[i] + f(cap,asst,i+1,x+1,n), cap[i] + f(cap,asst,i+1,x-1,n));
//     }

//     return dp[i][x]=ans;
// }

vector<vector<vector<int>>> dp(10, vector<vector<int>> (5, vector<int> (5, -1)));
int f2(int cap[], int asst[], int i, int ca, int cc, int n)
{

    if (i == n)
        return 0;

    if(dp[i][ca][cc]!=-1) return dp[i][ca][cc];

    int ans=0;
    if(ca==cc){
        ans+=asst[i] + f2(cap,asst,i+1,ca+1,cc,n);
    }
    else if(ca-cc==n-i){
        ans+=cap[i] + f2(cap,asst,i+1,ca,cc+1,n);
    }
    else{
        ans+= min(asst[i] + f2(cap,asst,i+1,ca+1,cc,n), cap[i] + f2(cap,asst,i+1,ca,cc+1,n));
    }

    return dp[i][ca][cc]=ans;
}

int main()
{
    int n;
    cout << "Enter the number of pilots:" << endl;
    cin >> n;

    int cap[n], asst[n];
    cout << "Enter the salaries:" << endl;
    for (int i = 0; i < n; i++)
    {
       
        cin >> cap[i] >> asst[i];
       
    }

    cout<<"Ans:"<<f2(cap,asst,0,0,0,n)<<endl;
}