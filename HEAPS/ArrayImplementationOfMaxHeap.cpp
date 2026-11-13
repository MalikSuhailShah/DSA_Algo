#include<iostream>
using namespace std;

class MaxHeap{

    public:
    int arr[50];
    int idx;

    MaxHeap(){
        idx=1;
    }

    void display(){
        for(int i=1;i<idx;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int size(){
        return idx-1;
    }

    int top(){
        return arr[1];
    }

    void push(int val){
        arr[idx]=val;
         int i=idx;
        idx++;

        while(i!=1){
            int parent=i/2;

            if(arr[parent]<arr[i]) swap(arr[parent], arr[i]);
            else break;
            i=parent;  
        }
       
    }

    void pop(){
        idx--;
        arr[1]=arr[idx];

        int i=1;
        while(i<idx){
            int left=2*i;
            int right=2*i+1;

            if(left>=idx && right>=idx) return ;
            else if(left>=idx){
                if(arr[i]<arr[right]) swap(arr[right],arr[i]);
                i=right;
            }
            else if(right>=idx){
                if(arr[left]>arr[i]) swap(arr[left],arr[i]);
                i=left;
            }
            else{ // right<=idx && left<= idx
                if(arr[left]>arr[right]){
                    if(arr[left]>arr[i]) swap(arr[left],arr[i]);
                    i=left;
                }
                else{
                     if(arr[i]<arr[right]) swap(arr[right],arr[i]);
                     i=right;
                }
            }
        }
    }
};


// WE can also add extra functionalities to like remove (that remove any paricular element from the heap),
// find(that tells whether that particular element is present in the heap or not)

// to remove any partular element from heap first replace it with last element and perform re arrangement

int main (){

    MaxHeap pq;
    pq.push(40);
    pq.push(30);
    pq.push(60);


    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.push(80);
    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.push(100);
    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.display();

    pq.pop();
    cout<<endl<<pq.top()<<" "<<pq.size()<<endl;
    pq.display();

     pq.pop();
    cout<<endl<<pq.top()<<" "<<pq.size()<<endl;
    pq.display();

     pq.pop();
    cout<<endl<<pq.top()<<" "<<pq.size()<<endl;
    pq.display();
}