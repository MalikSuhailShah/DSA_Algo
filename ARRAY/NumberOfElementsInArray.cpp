#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 5, 8, 6, 3, 5, 2, 5, 2, 2, 2, 8, 788, 8, 4, 4, 8848, 4, 84, 84, 848, 4};
    int n = sizeof(arr) / sizeof(arr[0]); // n = no. of elements of array
    cout<<n;
}