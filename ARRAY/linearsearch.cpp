#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the value of n->";
    cin >> n;
   
    int key;
    cout << "enter the value of key->";
    cin >> key;

     int arr[n];
    cout << "enter the elements of array->";
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool flag = false;

    for (int i = 0; i <= n - 1; i++)
    {
        if (key == arr[i])
        {
            flag = true;
        }
    }
    if(flag==true) cout<<"element present";
    else cout<<"element not present";
}