#include<iostream>
using namespace std;

class MinHeap{
    public:
    int arr[50];
    int idx;

    MinHeap(){
        idx=1;
    }

    int top(){
        return arr[1];
    }

    int size(){
        return idx-1;
    }

    void push(int val){
        arr[idx]= val;
        int i=idx;
        
        idx++;
        while(i!=1){
            int parent=i/2;
            if(arr[i]<arr[parent]) swap(arr[i], arr[parent]);
            else break;
            i=parent;
        }
    }

    void display(){
        for(int i=1;i<idx;i++){
            cout<<arr[i]<<" ";
        }
    }

    void pop(){

        if(idx<=1) {
            cout<<"Heap is Empty!!"<<endl;
            return;
        }
       idx--;
       arr[1]=arr[idx];

       // rearrangement
       int i=1;
       while(i<idx){
        int left=2*i;
        int right=2*i+1;

        if(left>idx){
            if(right<idx){
                 if(arr[right]<arr[i]) swap(arr[i],arr[right]);
                 i=right;
            }
            else break;
        }
        if(right>idx){
            if(left<idx){
                 if(arr[left]<arr[i]) swap(arr[i],arr[left]);
                 i=left;
            }
            else break;
        }
        if(right>idx && left>idx) return;

        if(arr[left]<arr[right]){
            if(arr[i]>arr[left]) swap(arr[i],arr[left]);
            i=left;
        }
        else{
            if(arr[right]<arr[i]) swap(arr[i],arr[right]);
            i=right;
        }
       }
    }
};
int main (){

    MinHeap pq;
    pq.push(40);
    pq.push(30);
    pq.push(60);


    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.push(10);
    cout<<pq.top()<<" "<<pq.size()<<endl;
    pq.push(1);
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