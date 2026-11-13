#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void display(queue<int> &  q){
    int n=q.size();

    int i=0;
    while(i!=n){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
        i++;
    }
    cout<<endl;
}

void reverseK(queue<int> & q,int k){
    int n=q.size();
    stack<int> st;
    int i=0;
    while(i<k){
        st.push(q.front());
        q.pop();
        i++;
    }

    while(st.size()){
        q.push(st.top());
        st.pop();
    }
    i=0;
    while(i<n-k){
        q.push(q.front());
        q.pop();
        i++;
    }
}

int main (){
    int k;
    cout<<"Enter the number of elements to be reversed:"<<endl;
    cin>>k;
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    display(q);
    reverseK(q,k);
    display(q);
    

   
}