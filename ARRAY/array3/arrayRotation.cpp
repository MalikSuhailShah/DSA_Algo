#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size->";
    cin >> n;

    int arr[n];
    cout << "enter the elements of array->";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "current elements of array -> ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int k;
    cout << "enter number of rotation->";
    cin >> k;

    int brr[n];
    for(int i=0;i<n;i++)
    {
        brr[i]=arr[i];
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[(j+1)%n]=brr[j];
        }
    }

    cout << "array after rotation -> ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}