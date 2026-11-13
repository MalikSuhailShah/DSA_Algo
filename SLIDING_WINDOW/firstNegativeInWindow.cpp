#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {2, 3, 4, 4, -7, -1, 4, -2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int t;
    cout << "Enter the window length:" << endl;
    cin >> t;

    int ans[n + t - 1];

    // BRUTE FORCE
    //  int i = 1;
    //  int j = t;

    // while (j <= n)
    // {
    // int prevIdx=-1;
    //     for (int k = i - 1; k < j; k++)
    //     {
    //         if (arr[k] < 0)
    //         {
    //             prevIdx=k;
    //             break;
    //         }
    //     }
    //      if(prevIdx==-1) v.push_back(1);
    //    else         v.push_back(arr[k]);

    //     i++;
    //     j++;
    // }

    // SLIDING WINDOW

    int prevIdx = -1;
    for (int i = 0; i < t; i++)
    {
        if (arr[i] < 0)
        {
            prevIdx = i;
            break;
        }
    }

    if (prevIdx == -1)
        ans[0] = 1;
    else
        ans[0] = arr[prevIdx];

    int i = 1;
int j = t;

while (j < n)
{
    if (prevIdx >= i)
    {
        // Previous negative is still inside window
        ans[i] = arr[prevIdx];
    }
    else
    {
        // Previous negative has left OR didn't exist
        prevIdx = -1;

        for (int p = i; p <= j; p++)
        {
            if (arr[p] < 0)
            {
                prevIdx = p;
                break;
            }
        }

        if (prevIdx != -1)
            ans[i] = arr[prevIdx];
        else
            ans[i] = 1;
    }

    i++;
    j++;
}

    for (int k = 0; k < n - t + 1; k++)
    {
        cout << ans[k] << " ";
    }
}