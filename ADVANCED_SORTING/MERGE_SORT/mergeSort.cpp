#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, vector<int> &b, vector<int> &ans)
{
    int n = a.size();
    int m = b.size();

    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
             ans[k++] = a[i++];
         else
            ans[k++] = b[j++];
    }

    if (i == n)
    {
        while (j < m)   ans[k++] = b[j++];
       
    }

    if (j == m)
    {
        while (i < n)   ans[k++] = a[i++];
       
    }

    return;
}

void mergeSort(vector<int> &res)
{

    int n = res.size();

    if (n == 1)
        return;

    int n1 = n / 2;
    int n2 = n - n / 2;

    vector<int> a(n1), b(n2);

    for (int i = 0; i < n1; i++)
    {
        a[i] = res[i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = res[i + n1];
    }

    // RECURSION
    mergeSort(a);
    mergeSort(b);

    // merging two arrays

    merge(a, b, res);
}

int main()
{
    int arr[] = {8, 7, 5, 4, 6, 3, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + n);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    mergeSort(v);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}