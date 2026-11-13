// Building the segment tree

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> segment_Tree;

void buildTree(vector<int> &arr, int i, int lo, int hi)
{
    if (lo == hi)
    {
        segment_Tree[i] = arr[lo];
        return;
    }

    int mid = lo + (hi - lo) / 2;

    buildTree(arr, 2 * i + 1, lo, mid);
    buildTree(arr, 2 * i + 2, mid + 1, hi);

    segment_Tree[i] = max(segment_Tree[2 * i + 1], segment_Tree[2 * i + 2]);

    return;
}

int getMax(int i, int lo, int hi, int l, int r)
{
    if (r < lo or l > hi)
        return INT_MIN;
    if (l <= lo and hi <= r)
        return segment_Tree[i];

    int mid = lo + (hi - lo) / 2;

    int leftAns = getMax(2 * i + 1, lo, mid, l, r);
    int rightAns = getMax(2 * i + 2, mid + 1, hi, l, r);

    return max(leftAns, rightAns);
}

int main()
{

    vector<int> arr = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = arr.size();

    segment_Tree.clear();
    segment_Tree.resize(4 * n);

    buildTree(arr, 0, 0, n-1);

    cout << getMax(0, 0, n - 1, 1, 4);
}