#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int mn = INT_MAX;
        int idx = -1;

        for (int j = i; j <= n - 1; j++)
        {
            if (mn > arr[j])
            {
                idx = j;
                mn = arr[j];
            }
        }
        swap(arr[idx],arr[i]);
    }

    cout << "The elements of the array after sorting are:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}