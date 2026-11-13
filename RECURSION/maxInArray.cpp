#include <iostream>
#include <climits>
#include<algorithm>
using namespace std;

void maxOfarray(int arr[], int n, int max)
{
    if (n == 0)
    {
        cout << "The maximum of elements of the array is:" << max << endl;
        return;
    }

    if (max < arr[n - 1])
        max = arr[n - 1];

    maxOfarray(arr, n - 1, max);
}

int maxArray(int arr[],int n)
{
    if(n==0) return INT_MIN;
   return max(arr[n-1],maxArray(arr,n-1));
}
int main()
{
    int arr[] = {9, 8, 7, 8, 5, 2, 6, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    
   // maxOfarray(arr, n, INT_MIN);

   cout<<"largest element is :"<<maxArray(arr,n);

    // cout << "The maximum of elements of the array is:" << maxVal;
}