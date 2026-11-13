#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void Reorder(queue<int> & q){

    int n=q.size();

    stack<int> st;

    for(int i=0;i<n/2;i++){
        st.push(q.front());
        
        q.pop();
      
    }

    while(st.size()){
        q.push(st.top());
        st.pop();
    }

     for(int i=0;i<n/2;i++){
        st.push(q.front());
        
        q.pop();
    }

    while(st.size()){
        q.push(st.top());
        st.pop();

        q.push(q.front());
        q.pop();
    }

    while(q.size()){
        st.push(q.front());
        q.pop();
    }

    while(st.size()){
        q.push(st.top());
        st.pop();
    }

    
}
int main (){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    int i=0;
    while(i<q.size()){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
        i++;
    }
    cout<<endl;

    Reorder(q);

    i=0;
    while(i<q.size()){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
        i++;
    }
    

}