// leetcode 2080

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class RangeFreqQuery {
public:
    vector<unordered_map<int, int>> segment_Tree;
    int n;

    unordered_map<int, int> addMaps(unordered_map<int, int>& mp1,
                                     unordered_map<int, int>& mp2) {
        unordered_map<int, int> ans;
        for (auto ele : mp1) {
            ans.insert(ele);
        }
        for (auto ele : mp2) {
            int key = ele.first, freq = ele.second;

            if (ans.find(key) != ans.end()) {
                ans[key] += freq;
            } else
                ans.insert({key, freq});
        }

        return ans;
    }

    void buildTree(vector<int>& arr, int i, int lo, int hi) {
        if (lo == hi) {
            int key = arr[lo], freq = 1;
            if (segment_Tree[i].find(key) != segment_Tree[i].end()) {
                segment_Tree[i][key] += freq;
                return;
            }
            segment_Tree[i][key] = freq;
            return;
        }

        int mid = lo + (hi - lo) / 2;

        buildTree(arr, 2 * i + 1, lo, mid);
        buildTree(arr, 2 * i + 2, mid + 1, hi);

        segment_Tree[i] =
            addMaps(segment_Tree[2 * i + 1], segment_Tree[2 * i + 2]);
    }

    
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        segment_Tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
        
    }

    int getFreq(int i, int lo, int hi, int l, int r, int value) {
        if(l>hi or r<lo) return 0;
        if(l<=lo and hi<=r) {
            if(segment_Tree[i].find(value) != segment_Tree[i].end()) return segment_Tree[i][value];

            return 0;
        }
        int mid = lo + (hi-lo)/2;
        int leftAns = getFreq(2*i+1,lo, mid, l,r,value);
        int rightAns = getFreq(2*i+2, mid+1, hi, l,r,value);

        return leftAns + rightAns;
    }
    int query(int left, int right, int value) {
       return getFreq(0, 0, n - 1, left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main ()
{

}