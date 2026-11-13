#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int pivotelement = arr[si];

    int count = 0;

    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] <= pivotelement)
            count++;
    }

    int pivotIdx = si + count;

    swap(arr[si], arr[pivotIdx]);

    int i = si, j = ei;

    while (i < pivotIdx && j > pivotIdx)
    {

        if (arr[i] <= arr[pivotIdx])
            i++;
        if (arr[j] > arr[pivotIdx])
            j--;

        else if(arr[i]>arr[pivotIdx] && arr[j] < arr[pivotIdx]){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    return pivotIdx;
}

void quickSort(int arr[], int si, int ei)
{

    if (si >= ei)
        return;

    int pi = partition(arr, si, ei);

    quickSort(arr, si, pi - 1);
    quickSort(arr, pi + 1, ei);

    return;
}

int main()
{

    int arr[] = {5, 8, 2, 3, 4, 1, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
