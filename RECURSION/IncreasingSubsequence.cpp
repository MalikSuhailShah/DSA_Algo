#include <iostream>
#include <vector>

using namespace std;

void SubSequenceIn(int arr[], int n, int idx, vector<int> v, vector<vector<int>> &a, int k)
{
    if (idx == n)
    {

        if (v.size() == k)
            a.push_back(v);

        return;
    }

    if ((v.size() + (n - idx)) < k)// this will make the code faster
        return;

    SubSequenceIn(arr, n, idx + 1, v, a, k);
    v.push_back(arr[idx]);
    SubSequenceIn(arr, n, idx + 1, v, a, k);
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int k;
    cout << "Enter the length of subsequence:" << endl;
    cin >> k;

    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    vector<vector<int>> a;

    SubSequenceIn(arr, n, 0, v, a, k);

    for (int i = 0; i < a.size(); i++)
    {
        for (int ele : a[i])
        {
            cout << ele;
        }
        cout << endl;
    }
}