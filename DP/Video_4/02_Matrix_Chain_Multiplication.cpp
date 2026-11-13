/*Given an array arr[] representing the dimensions of a sequence of matrices, where the \(i^{th}\) matrix has dimensions arr[i-1] × arr[i], find the minimum number of scalar multiplications required to multiply all the matrices.*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> dp;

// top down solution
int f(int i, int j, vector<int> &arr)
{
    if (i == j or i + 1 == j) // when i+1 =j then we are taking two elements of the array so, this form only one mtarix, no matrix forms when i==j
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i + 1; k < j; k++)
    {

        ans = min(ans, f(i, k, arr) + f(k, j, arr) + arr[i] * arr[k] * arr[j]); // checking for all the possible multiplication
    }

    return dp[i][j] = ans;
}

// bottom up solution

int fbu(vector<int> &v)
{

    int n = v.size();
   

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // n - len + 1 tells us how many possible starting positions (i) are available for a subarray of length len within an array of size n.
    // when len==2 the it will contain two elements and only  one matrix can be form there , so number of multiplication will be zero
    
    for (int len = 3; len <= n; len++)// len = basically the length of array of subproblem
    {
        for (int i = 0; i < n - len + 1; i++)  // i iterates over the complete length of subproblem array
        {
            int j = i + len - 1; // last index of that particular subproblem

            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[j] * v[k]);
            }
        }
    }

    return dp[0][n-1];
}

// int fbu(vector<int> &arr) {
//     int n = arr.size();

//     vector<vector<int>> dp(n, vector<int>(n, 0));

//     // len = chain length
//     for (int len = 2; len < n; len++) {
//         for (int i = 1; i < n - len + 1; i++) {
//             int j = i + len - 1;
//             dp[i][j] = INT_MAX;

//             for (int k = i; k < j; k++) {
//                 dp[i][j] = min(dp[i][j],
//                                dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
//             }
//         }
//     }

//     return dp[1][n - 1];
// }

int main()
{
    int n;
    cout << "Enter the value of n:" << endl;
    cin >> n;

    vector<int> v;

    dp.clear();
    dp.resize(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << fbu(v) << endl;
}