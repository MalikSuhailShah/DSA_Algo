#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of array->";
    cin >> n;
    int arr[n];
    cout << "enter the elements of array->";
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }
    int max = INT_MIN;
    int secMax = INT_MIN;
    for (int i = 0; i <= n - 1; i++)
    {
        if (max < arr[i]) max=arr[i];
    }
    for(int i=0;i<=n-1;i++)
    {
        if(arr[i]!=max && secMax<arr[i]) secMax=arr[i];

    }
    cout<<max<<endl<<"second largest element of array is "<<secMax;
}