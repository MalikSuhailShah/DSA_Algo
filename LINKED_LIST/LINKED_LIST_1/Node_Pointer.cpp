#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    //CONSTRUCTOR

    Node (int value){
        this->value=value;
        this->next=NULL;
    }
};

int main (){

    Node * a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node * d=new Node(40);


    //a,b,c,d are all Node type pointers that stores address of thier corresponding Node
    a->next=b;
    b->next=c;
    c->next=d;



    ///Acessing Linked List

    Node* temp=a;

    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }

}