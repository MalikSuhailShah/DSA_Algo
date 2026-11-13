#include <iostream>
#include <vector>
using namespace std;

int missing(vector<int> &arr)
{
    int i = 0, n = arr.size();

    while (i < n)
    {
        int correctIdx = arr[i];

        if (arr[i] == i || arr[i] == n)
            i++;
        else
            swap(arr[i], arr[correctIdx]);
    }
    int misNum = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != (i))
        {
            misNum = i;
            break;
        }
    }

    return misNum;
}
int main()
{

    vector<int> v = {1, 2, 3, 4, 6, 7, 0};

    cout << missing(v);
}