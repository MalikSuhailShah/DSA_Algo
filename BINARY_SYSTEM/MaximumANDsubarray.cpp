#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {1, 5, 7, 8, 9, 9, 9, 6, 2, 5, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_ele = INT_MIN;
    int count = 0;
    int ans = 0;

    for (int x : arr)
    {

        if (x > max_ele)
        {
            max_ele = x;
            count = 1;
            ans = 1;
        }
        else if (x == max_ele)
        {
            count++;
            ans = max(ans, count);
        }
        else
        {
            count = 0;
        }
    }

    cout << "The length of subarray having maximum value of and operation:" << ans << endl;
}