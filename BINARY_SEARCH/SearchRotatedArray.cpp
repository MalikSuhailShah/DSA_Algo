#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // 1. Find pivot (index of smallest element)
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {

            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        int pivot = lo;

        // 2. Decide which sorted half to search

        if (target >= nums[pivot] && target <= nums[n - 1]) {

            // Search right half
            lo = pivot;
            hi = n - 1;

        } else {

            // Search left half
            lo = 0;
            hi = pivot - 1;
        }

        // 3. Normal binary search

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                lo = mid + 1;

            else
                hi = mid - 1;
        }

        return -1;
    }
};
int main()
{
    vector<int> arr = {3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter the target:" << endl;
    cin >> target;

    Solution obj;

    cout<<obj.search    (arr, target);
    
    

}