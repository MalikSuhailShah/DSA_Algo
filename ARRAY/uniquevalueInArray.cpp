#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of an array:\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // checking for unique element
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (i != j and arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }

        if (not flag)
        {
            cout << arr[i] << "\n";
        }
    }

    return 0;
}