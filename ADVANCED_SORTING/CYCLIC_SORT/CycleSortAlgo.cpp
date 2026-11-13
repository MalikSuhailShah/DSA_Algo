#include <iostream>
using namespace std;
int main()
{
    int arr[] = {4, 1, 6, 2, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;


    //CYCLE SORT ALGO
    int i = 0;

    while (i < n)
    {

        if (i != arr[i] - 1)
        {
            int x = arr[i] - 1;
            swap(arr[i], arr[x]);
        }
        else
            i++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}