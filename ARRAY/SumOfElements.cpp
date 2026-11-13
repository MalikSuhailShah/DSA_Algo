#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the value of n->";
    cin >> n;
    int arr[n];
    cout << "enter the elements of array->";
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }
    int sum=0;
    for (int i = 0; i < n; i++)
    {
       sum+=arr[i];
    }
    cout<<sum;
}
