#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void AllSubsets(vector<int> orig, vector<int> ans, vector<vector<int>> &FinalAns, int idx)
{
    if (idx == orig.size())
    {
        FinalAns.push_back(ans);
        return;
    }

    AllSubsets(orig, ans, FinalAns, idx + 1);

    ans.push_back(orig[idx]);

    AllSubsets(orig, ans, FinalAns, idx + 1);
}

vector<vector<int>> AllSubsetDuplicate(vector<int> orig, vector<int> ans, vector<vector<int>> &finalAns, int idx)
{

    if (idx == orig.size())
    {
        finalAns.push_back(ans);
        return finalAns;
    }

    // inclusive call

    ans.push_back(orig[idx]);

    AllSubsetDuplicate(orig, ans, finalAns, idx + 1);

    while (orig[idx] == orig[idx + 1])
        idx++; // exclude all similar elements

    ans.pop_back();
    AllSubsetDuplicate(orig, ans, finalAns, idx + 1);
}

void InSubsequence(vector<vector<int>> &final, vector<int> &ans, vector<int> &nums, int idx, int k)
{
    if (idx == nums.size())
    {
        if (ans.size() == k)
            final.push_back(ans);
        return;
    }

    int val = nums[idx];
    ans.push_back(val);

    InSubsequence(final, ans, nums, idx + 1, k);

    ans.pop_back();

    InSubsequence(final, ans, nums, idx + 1, k);
}

void generatePermutation(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string right = str.substr(i + 1);
        string left = str.substr(0, i);
        generatePermutation(left + right, ans + ch);
    }
}

void subarray(vector<int> &nums, vector<int> ans, int idx)
{
    if (idx == nums.size())
    {
        for (int ele : ans)
            cout << ele << " ";

        cout << endl;
        return;
    }

    subarray(nums, ans, idx + 1); // not inclusive

    if (ans.size() == 0 || nums[idx - 1] == ans[ans.size() - 1])
    {
        ans.push_back(nums[idx]);
        subarray(nums, ans, idx + 1);
    }
}

void generateBinarySting(int n, string ans)
{
    if (ans.length() == n)
    {
        cout << ans << " ";
        return;
    }

    generateBinarySting(n, ans + '0');

    if (ans.size() == 0 || ans[ans.size() - 1] != '1')
        generateBinarySting(n, ans + '1');
}

string KthPermutation(string str, int k, string ans)
{
    int n = str.length();

    if (n == 1)
    {
        ans += str;
        return ans;
    }

    int fact = 1;
    for (int i = 2; i < n; i++)
        fact *= i; // calculating the (n-1)! to find number of  permutation starting from diff character

    int idx = k / fact;

    if (k % fact == 0)
        idx--; // this means the last permutation for any particular first character

    char ch = str[idx]; // first char of the required permutation

    int q;
    if (k % fact == 0)
        q = fact;
    else
        q = k % fact;

    string left = str.substr(0, idx), right = str.substr(idx + 1);
     return KthPermutation(left + right, q, ans + ch);
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans;
    subarray(nums, ans, 0);
}
