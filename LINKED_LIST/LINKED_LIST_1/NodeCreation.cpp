#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node (int value){
        this->value=value;
        this->next=NULL;
    }
};

void display(Node a)
{
    Node temp=a;
    while(true){
        cout<<temp.value<<" ";
        if(temp.next==NULL) break;
        temp=(*temp.next);
    }
}

int main (){

    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    //Linking NOdes with each other
    a.next=&b;
    b.next=&c;
    c.next=&d;


    //Accessing Nodes

   // cout<<a.value<<" "<<b.value<<" "<<c.value<<" "<<d.value<<endl;

    // cout<<(a.next->next->next->value)<<endl;
    display(a);
}