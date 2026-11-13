// Lazy Propagation is an optimization technique used in Segment Trees to efficiently handle range updates and range queries.

#include <iostream>
#include <vector>

using namespace std;

vector<int> lazy;
vector<int> segment_Tree;

void buildTree(vector<int> &arr, int i, int lo, int hi)
{
    if (lo == hi)
    {
        segment_Tree[i] = arr[lo];
        return;
    }

    int mid = lo + (hi-lo)/2;

    buildTree(arr, 2*i+1, lo, mid);
    buildTree(arr, 2*i+2, mid+1, hi);

    segment_Tree[i] = segment_Tree[2*i+1] + segment_Tree[2*i+2];

}
int getSum(int i, int lo, int hi, int l, int r){
    if(lazy[i]!=0){
        int range = hi-lo+1;
        segment_Tree[i] += range*lazy[i];
        if(lo!=hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }

        lazy[i] = 0;
    }
    if( l>hi or r<lo) return 0;
    if( l<=lo and hi <= r) return segment_Tree[i];

    int mid = lo + (hi-lo)/2;
    int leftAns = getSum(2*i+1, lo, mid, l, r);
    int rightAns = getSum(2*i+2, mid+1, hi, l, r);

    return leftAns + rightAns;
}

void updateTree(int i,int lo, int hi, int l, int r, int value){
    if(lazy[i] != 0){
        int range = hi-lo+1;
        segment_Tree[i] += range*lazy[i];

        if(lo!=hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }

        lazy[i] =0;
    }

    if(l>hi or r<lo) return;
    if(l<=lo and hi <= r){
        int range = hi - lo +1;
        segment_Tree[i] += range*value;

        if(lo!=hi){
            lazy[2*i+1] +=  value;
            lazy[2*i+2] +=  value;
        }

        return;
    }

    int mid = lo + (hi - lo)/2;

    updateTree(2*i+1, lo, mid, l , r, value);
    updateTree(2*i+2, mid+1, hi, l , r, value);

    segment_Tree[i] = segment_Tree[2*i+1] + segment_Tree[2*i+2];
}

int main()
{

    vector<int> arr = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = arr.size();

    
    segment_Tree.resize(4 * n);
    lazy.resize(4*n);

    buildTree(arr, 0, 0, n - 1);

    cout<<getSum(0,0,n-1,1,3)<<"\n";
    updateTree(0,0,n-1,2,5,10);
    cout<<getSum(0,0,n-1,1,3);
}