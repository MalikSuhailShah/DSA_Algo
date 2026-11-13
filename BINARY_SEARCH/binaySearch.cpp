#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 9, 10, 15, 18, 21, 25, 27};

    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter the target:";
    cin >> target;

    int low = 0;
    int high = n - 1;
    bool flag = false;

    while (low <= high)
    {
        int mid =low+ ( high-low) / 2;//equivalent to (low+high)/2

        if (target == arr[mid])
        {
            cout << mid;
            flag = true;
            break;
        }
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    
    if(!flag) cout<<"The element is not present";
}