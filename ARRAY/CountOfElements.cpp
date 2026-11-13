// count of elements greater than particular input
#include <iostream>
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
    int x;
    cout << "enter the value of X->";
    cin >> x;
    int count = 0;
    for (int i = 0; i <= n - 1; i++)

    {
        if (arr[i] > x)
            count++;
    }
    cout << "the nummber of elements greater than x is " << count;
}