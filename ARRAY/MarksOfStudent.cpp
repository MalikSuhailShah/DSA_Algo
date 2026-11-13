#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of students->";
    cin >> n;
    int arr[n];
    cout << "enter the marks of students->";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "the  roll number of students with marks less than 35->";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 35)
        {
            cout << i << " ";
        }
    }
}