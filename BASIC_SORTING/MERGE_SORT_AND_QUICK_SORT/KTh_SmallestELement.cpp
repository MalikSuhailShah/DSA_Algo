#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int si, int ei)
{
    int count = 0;
    int m = (si + ei) / 2;
    int pivotEle = arr[m];

    for (int i = si ; i <= ei; i++)
    {
        if (i == m)
            continue;
        else if (pivotEle >= arr[i])
            count++;
    }

    int pivotIdx = count + si;
    swap(arr[m], arr[pivotIdx]);
    int i = si, j = ei;

    while (i < pivotIdx && j > pivotIdx)
    {
        if (arr[i] <= pivotEle )
            i++;
        else if (pivotEle < arr[j])
            j--;
        else if (pivotEle < arr[i] && pivotEle >= arr[j])
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }

    return pivotIdx;
}

int KthSmallest(vector<int> &arr, int si, int ei, int k)
{

    if (si == ei)
        return arr[si];

    int pivotIdx = partition(arr, si, ei);
    int target = k - 1;

    if (target < pivotIdx)
        return KthSmallest(arr, si, pivotIdx - 1, k);
    else if (target > pivotIdx)
        return KthSmallest(arr, pivotIdx + 1, ei, k);
    else
        return arr[pivotIdx];
}

int main()
{
    vector<int> v = {3, 1, 2, 3, 3, 4, 3};
    int k = 3;
    int n = v.size();

    cout << KthSmallest(v, 0, n - 1, k);
}
