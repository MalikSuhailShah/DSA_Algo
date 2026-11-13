
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int grid[4][4] = {
                    {0,20,42,25}, 
                    {20,0,30,34}, 
                    {42,30,0,10}, 
                    {25,34,10,0}
                };

int dp[10][1 << 10];

int tsp(int curr, int visited_mask, int n)
{
    if (visited_mask == ((1 << n) - 1))
        return grid[curr][0]; // taking 0 as a src node and grid[curr][0] = distance of leaf node form src node
   
    if (dp[curr][visited_mask] != -1)
        return dp[curr][visited_mask];

    int ans = INT_MAX;
    for (int neighbour = 0; neighbour < n; neighbour++)
    {
        
        if ( (visited_mask & (1 << neighbour)) == 0)
        {
            ans = min(ans,grid[curr][neighbour] + tsp(neighbour, visited_mask | (1 << neighbour), n));
        }
    }

    return dp[curr][visited_mask] = ans;
}

int main()
{
    memset(dp, -1, sizeof dp);

    cout<<tsp(0,1,4);

    return 0;
}