//LeetCode - 480 => https://leetcode.com/problems/sliding-window-median/description/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

 
class Solution {
public:
    double CalculateMed(priority_queue<int>& left,
                        priority_queue<int, vector<int>, greater<int>>& right,
                        int& x, int& y) {
        double med;
        if (x == y) {
            med = ((double)left.top() + right.top()) / 2.0;
        } else if (x > y)
            med = 1.0 * (left.top());
        else
            med = 1.0 * (right.top());

        return med;
    }

    void BalanceHeaps(priority_queue<int>& left,
                      priority_queue<int, vector<int>, greater<int>>& right,
                      int& x, int& y) {
        while (x > (y + 1)) {
            right.push(left.top());
            left.pop();
            x--;
            y++;
        }
        while (y > (x + 1)) {
            left.push(right.top());
            right.pop();
            y--;
            x++;
        }

        if (!left.empty() && !right.empty() && left.top() > right.top()) {
            int a = left.top();
            left.pop();
            int b = right.top();
            right.pop();

            left.push(b);
            right.push(a);
        }
    }

    template <typename T> // no need to create seperate  functions for min and
                          // max heaps this deduce the type of heap by itself

    void deletionFromMap(T& heap, unordered_map<int, int>& mp) {

        while (!heap.empty() && mp[heap.top()] > 0) {
            mp[heap.top()]--;
            if (mp[heap.top()] == 0)
                mp.erase(heap.top());
            heap.pop();
        }
    }

    void insertElementInHeaps(priority_queue<int>& left,
                         priority_queue<int, vector<int>, greater<int>>& right,
                         int val, int& x, int& y) {
        if (left.size() == 0 || val < left.top()) {
            left.push(val);
            x++;
        } else {
            right.push(val);
            y++;
        }
        BalanceHeaps(left, right, x, y);
    }

    vector<double> SlindingWindowMedian1(vector<int>& arr, int k) {

        int n = arr.size();

        int i = 0, j = k - 1;

        // calculating median for first window

        priority_queue<int> left;                             //(Max Heap)
        priority_queue<int, vector<int>, greater<int>> right; //(Min Heap)

        int x = 0; // left heap size
        int y = 0; // right heap size
        for (int p = i; p <= j; p++) {
            insertElementInHeaps(left, right, arr[p], x, y);
        }
        double med = CalculateMed(left, right, x, y);

        vector<double> ans;
        ans.push_back(med);

        unordered_map<int, int> mp;
        while (j < n - 1)

        {
            mp[arr[i]]++;
            if (arr[i] <= left.top())
                x--;
            else
                y--;

            // deletionFromMap(left, mp);
            // deletionFromMap(right, mp);

            


            BalanceHeaps(left, right, x, y);

            // sliding the window
            i++;
            j++;

            insertElementInHeaps(left, right, arr[j], x, y);
            deletionFromMap(left, mp);
            deletionFromMap(right, mp);

            BalanceHeaps(left, right, x, y);

            // Pushing calculate median

            med = CalculateMed(left, right, x, y);
            ans.push_back(med);
        }

        return ans;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        if (k == 1) {
            vector<double> res(nums.size());
            for (int i = 0; i < nums.size(); i++) {
                res[i] = nums[i] * 1.0;
            }
            return res;
        };
        vector<double> ans = SlindingWindowMedian1(nums, k);
        return ans;
    }
};
int main()
{
    
}