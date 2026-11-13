#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {19, 12, 23, 8, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(n, 0);//0 refers to that element not visited

    int t = 0;
    for (int i = 0; i < n; i++)
    {
        
        int min = INT_MAX;
        int idx = -1;
        for (int j = 0; j < n; j++)
        {

            if (v[j] == 1)
                continue;
            else
            {
                if (min > arr[j])
                {
                    min = arr[j];
                    idx = j;
                }
            }
        }
        arr[idx] = t;
        t++;
        v[idx]=1;// 1 refers to that element   is visited

    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}