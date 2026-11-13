#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long int;

using namespace std;

long long int n, m; // dimensions of the grid
char mat[105][105];// input matrix

long long int dp[105][105][105];

long long int f(long long int i, long long int j, long long int x, long long int y)
{
    if (i > n or j > m or x > n or y > m or mat[i][j] == '#' or mat[x][y] == '#')
        return 0;
    if (i == n and j == m) // tourist 1 already at destination and since x+y = i+j => both tourist reach the destination at same time 
        return mat[i][j] == '*';

    if (dp[i][j][x] != -1)
        return dp[i][j][x];

    long long int result = INT_MIN;

    result = max(result, f(i + 1, j, x + 1, y));
    result = max(result, f(i + 1, j, x, y + 1));
    result = max(result, f(i, j + 1, x + 1, y));
    result = max(result, f(i, j + 1, x, y + 1));

    // if both tourist at interested locations
    
        result += mat[i][j] == '*';
   
        result += mat[x][y] == '*';

    // removing duplicated count

   if(mat[i][j]=='*' and i==x and j==y) result--;
   
   return dp[i][j][x] = result;
}

int main()
{

    int t;
    cin>>t;
    while(t--){
        memset(dp,-1, sizeof dp);

        cin>>m>>n;


        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mat[i][j];
            }
        }

        cout<<"Ans:"<<f(1,1,1,1)<<endl;
    }
}