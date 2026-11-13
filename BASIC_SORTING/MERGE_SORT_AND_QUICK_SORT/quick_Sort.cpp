#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int si, int ei)
{
    int pivotEle = v[si];

    int count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (v[i] <= pivotEle)
            count++;
    }
    int pivotIdx = si + count;

    swap(v[pivotIdx], v[si]);

    int i = si, j = ei;

    while (i < pivotIdx && j > pivotIdx)
    {
        if (v[i] <= pivotEle)
            i++;
        else if (v[j] > pivotEle)
            j--;
        else if (v[i] > pivotEle && v[j] < pivotEle)
        {
            swap(v[i], v[j]);
            i++, j--;
        }
    }

    return pivotIdx;
}

void quickSort(vector<int> &arr, int si, int ei)
{
    if (si >= ei)
        return;

    int pivotIdx = partition(arr, si, ei);

    quickSort(arr, si, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, ei);
}
int main()
{

    vector<int> v = {5, 4, 3,78, 2, 789,-98,
        1};
    int n = v.size();
    int si = 0, ei = n - 1;

    quickSort(v, si, ei);
    for (int ele : v)
        cout << ele << " ";
}