#include <bits/stdc++.h>
using namespace std;

vector<double> slidingWindowMedian(vector<int>& nums, int k)
{
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    unordered_map<int,int> delayed;

    int leftSize = 0, rightSize = 0;

    function<void()> pruneLeft = [&]() {
        while(!left.empty() && delayed[left.top()]){
            delayed[left.top()]--;
            left.pop();
        }
    };

    function<void()> pruneRight = [&]() {
        while(!right.empty() && delayed[right.top()]){
            delayed[right.top()]--;
            right.pop();
        }
    };

    function<void()> balance = [&]() {
        if(leftSize > rightSize + 1){
            right.push(left.top());
            left.pop();
            leftSize--;
            rightSize++;
            pruneLeft();
        }
        else if(leftSize < rightSize){
            left.push(right.top());
            right.pop();
            leftSize++;
            rightSize--;
            pruneRight();
        }
    };

    function<void(int)> addNum = [&](int num) {
        if(left.empty() || num <= left.top()){
            left.push(num);
            leftSize++;
        }
        else{
            right.push(num);
            rightSize++;
        }
        balance();
    };

    function<void(int)> removeNum = [&](int num) {
        delayed[num]++;

        if(num <= left.top()){
            leftSize--;
            if(num == left.top())
                pruneLeft();
        }
        else{
            rightSize--;
            if(num == right.top())
                pruneRight();
        }

        balance();
    };

    function<double()> getMedian = [&]() {
        if(k % 2)
            return (double)left.top();
        return ((double)left.top() + right.top()) / 2.0;
    };

    vector<double> ans;

    for(int i=0;i<nums.size();i++)
    {
        addNum(nums[i]);

        if(i >= k-1)
        {
            ans.push_back(getMedian());
            removeNum(nums[i-k+1]);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<double> result = slidingWindowMedian(nums,k);

    for(double x : result)
        cout<<x<<" ";
}