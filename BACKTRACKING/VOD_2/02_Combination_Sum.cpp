// leetcode 40 : https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int>& cand, int target, int idx, vector<int>& subset) {

        if (target == 0) {
            result.push_back(subset);
            return;
        }

        if (idx >= cand.size())
            return;

            
        if (cand[idx] > target)
            return;

            
        if (target >= cand[idx]) {
            subset.push_back(cand[idx]);
            f(cand, target - cand[idx], idx + 1, subset);
            subset.pop_back();
        }

        int j = idx + 1;
        while (j < cand.size() and cand[j] == cand[j - 1])
            j++;

        f(cand, target, j, subset);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        result.clear();
        vector<int> subset;
        f(candidates, target, 0, subset);

        return result;
    }
};

int main (){

}