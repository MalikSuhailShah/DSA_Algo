#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of array=>";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        product *= arr[i];
    }

    cout << "sum of all elements of array is =>" << sum << endl;
    cout << "product of all elements of array is =>" << product << endl;

  
    return 0;
}