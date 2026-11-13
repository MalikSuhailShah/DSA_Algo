
// THEORY
// heapify algorithm basically refers to conversion of a given array into the heap
// if n=size of the heap then if n=even => no. of leaf nodes=n/2;
// if n=odd => no. of leaf nodes= n/2 +1;
// make complete binary tree from the given array
//leaf nodes are already satisfy heap property so inorder to convert array into heap we first identify
// the leafnodes in array => 1.if size of array=even => leaf nodes is last half of the array
                        //   2. if size of the array if odd => leaf nodes are last n/2 +1 elements of the array
// the from leaf nodes proceed to higher level node till the root and at every node validate heap property
// we use heapify algorithm to convert a given array into a heap(either max heap or min heap)

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void heapify(vector<int> & arr,int i){
   int n=arr.size();

   while(true){
        int left=2*i;
        int right=2*i+1;

        if(left>=n) return;//=> because right index hmesha left index se aage hoga  "=" is used to maintain 1 based indexing
        else{//=> left<n
                if(right>=n){// only left child is there and left==n
                    if(arr[left]<arr[i]){ // only one time swapping will perform
                        swap(arr[i],arr[left]);
                        i=left;
                       
                    }
                    else break;
                }
                else{// means both childs are there, calculate minimum of both first the do swapping
                    if(arr[right]<arr[left]){
                        if(arr[right]<arr[i]){
                            swap(arr[right],arr[i]);
                            i=right;
                        }
                    }
                    else{
                        if(arr[left]<arr[i]){
                            swap(arr[left],arr[i]);
                            i=left;
                        }
                    }

            }
         }
     }
    
}

int main ()
{
   vector<int> arr={INT_MIN,10,2,14,11,1,4};// we consider indexing from 1 only to maintain mathmatics standard
    int n=arr.size();

    for(int i=1;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   for(int i=n/2;i>=1;i--){
    heapify(arr, i);
   }
    for(int i=1;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}