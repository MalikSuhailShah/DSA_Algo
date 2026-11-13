#include <iostream>
using namespace std;

void printReverse(int arr[], int n)
{

    if (n == 0)
    {
        return;
    }
    cout << arr[n - 1] << " ";

    return printReverse(arr, n-1);
}
int main()
{

    int arr[] = {5, 6, 8, 8, 9, 6, 2, 4, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    printReverse(arr, n);
}