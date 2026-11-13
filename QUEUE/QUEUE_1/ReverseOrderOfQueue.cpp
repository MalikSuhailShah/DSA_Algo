#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseDisplay(queue<int> & q){

    stack<int> st;
    int n=q.size();
    int i=0;
    while(i!=n){
        st.push(q.front());
        q.push(q.front());
        q.pop();
        i++;
    }

    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void reverseQueue(queue<int> & q){
    int n=q.size();
    stack<int> st;
    int i=0;

    //empty the queue into stack
    while(i!=n){
        st.push(q.front());
        q.pop();
        i++;
    }
//empty the stack into queue
    while(st.size()){
        q.push(st.top());
        st.pop();
    }
}
int main (){

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

   reverseQueue(q);
   reverseDisplay(q);
    
}