#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    // lower Bound (first Element >= target, first element satisfying this condition)
    int lo = 0;
    int hi = arr.size()-1;
    int lowerBound = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

     
        if (arr[mid] < target)
        {
            // arr[mid] can not be lower Bound
            lo = mid+1;
        }
        else {
            lowerBound = mid;
            // arr[mid] can also be an answer
            hi=mid-1;
        }
    }

    if(lowerBound == -1 ) cout<<"Lower Bound does not exist!!"<<"\n";
    else cout<<"lower Bound :- "<<arr[lowerBound];
}