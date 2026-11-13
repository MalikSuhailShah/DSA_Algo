// mutable => array is updated after it is given
// leetcode 307 

#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
    vector<int> segment_Tree;
    int n;
   
    void buildTree(vector<int> &nums, int i, int lo, int hi){
        if(lo==hi){
            segment_Tree[i] = nums[lo];
            return;
        }
        int mid = lo + (hi-lo)/2;

        buildTree(nums, 2*i+1, lo, mid);
        buildTree(nums, 2*i+2, mid+1, hi);

        segment_Tree[i] = segment_Tree[2*i+1] + segment_Tree[2*i+2];
    }
    NumArray(vector<int>& nums) {
         n = nums.size();
        segment_Tree.resize(4*n);
        buildTree(nums, 0, 0, n-1);
        
    }
    
    void updateRange(int i, int lo, int hi, int index, int value){
        if(lo == hi) {
            // base case
            segment_Tree[i] = value;
            return;
        }

        int mid = lo + (hi-lo)/2;
        if(index > mid) updateRange(2*i+2, mid+1, hi, index, value);
        else updateRange(2*i+1, lo, mid, index, value);

        segment_Tree[i] = segment_Tree[2*i+1] + segment_Tree[2*i+2];
        return;
    }
    void update(int index, int val) {
        updateRange(0,0,n-1,index, val);
        
    }
    
    int getSum(int i , int lo, int hi, int l,int r){
        if(l>hi or r<lo) return 0;
        if(l<=lo and hi<=r) return segment_Tree[i];

        int mid = lo + (hi-lo)/2;
        int leftAns = getSum(2*i+1, lo, mid, l,r);
        int rightAns = getSum(2*i+2, mid+1, hi, l,r);

        return leftAns + rightAns;
    }
    int sumRange(int left, int right) {
        return getSum(0,0,n-1,left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

 int main (){
    
 }