#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size of array=>";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
      // swapping min an max elements
    int max = INT32_MIN;
    int min = INT32_MAX;
    int minidx = -1;
    int maxidx = -1;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            maxidx = i;
        }
        if (min > arr[i])
        {
            min = arr[i];
            minidx = i;
        }
    }
    swap(arr[minidx],arr[maxidx]);
    cout<<endl;
     for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    }
    return 0;
}