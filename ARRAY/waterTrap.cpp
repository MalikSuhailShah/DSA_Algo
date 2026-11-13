#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n), next(n);

        prev[0] = -1;
        int mx = arr[0];
        for (int i = 1; i < n; i++)
        {
            prev[i] = mx;
            if (mx < arr[i])
                mx = max(mx, arr[i]);
        }

        mx = arr[n - 1];
        next[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            next[i] = mx;
            if (mx < arr[i])
                mx = max(mx, arr[i]);
        }

        vector<int> Min(n);

        for (int i = 0; i < n; i++)
        {
            Min[i] = min(prev[i], next[i]);
        }

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (Min[i] > arr[i])
                sum += Min[i] - arr[i];
        }
        return sum;
    }
};
int main()
{
}