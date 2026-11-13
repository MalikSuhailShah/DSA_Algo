#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *Head;
    Node *tail;
    int size;

    LinkedList()
    { //=>constructor
        Head = tail = NULL;
        size = 0;
    }

    void InsertAtHead(int value)
    {
        Node *temp = new Node(value);
        if (size == 0)
            Head = tail = temp;

        else
        {
            temp->next = Head;
            Head = temp;
        }
        size++;
    }

    void InsertAtTail(int value)
    {
        Node *temp = new Node(value);
        if (size == 0)
            Head = tail = temp;
        else
        {

            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void InsertAtIdx(int value, int idx)
    {

        if (idx < 0 || idx > size)
        {
            cout << "Inavlid Index!!" << endl;
            return;
        }
        else if (idx == 0)
            InsertAtHead(value);
        else if (idx == size - 1)
            InsertAtTail(value);
        else
        {
            Node *t = new Node(value);
            Node *temp = Head;

            for (int i = 1; i <= idx - 1; i++)
            {
                temp = temp->next;
            }

            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    int GetAtIdx(int idx)
    {
        if(idx<0 || idx>size-1) {
            cout<<"Invalid Index!!"<<endl;
            return -1;

        }
        else if(idx==0) return Head->value;
        else if(idx==size-1) return tail->value;

        else {
            Node* temp=Head;

            for(int i=1;i<=idx;i++){
                temp=temp->next;
            }

            return temp->value;
        }
    }


    void DeleteAtHead(){
        if(size==0) cout<<"List is empty!!"<<endl;
        else{
            Head=Head->next;
            size--;
        }
    }

    void DeleteAtTail(){
        if(size==0){
            cout<<"List is empty!!"<<endl;
            return ;
        }
        else{
            Node* temp=Head;
            for(int i=0;i<size-1;i++){
                temp=temp->next;
            }
            tail = temp;
            temp->next=NULL;
            size--;
        }
    }

    void DeleteAtIndex(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid Index!!"<<endl;
            return ;
        }
        else if(idx==0) DeleteAtHead();
        else if(idx==size-1) DeleteAtTail();
        else{
            Node * temp=Head;

            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }

            temp->next=temp->next->next;
            size--;
        }
    }

    void Display(){
        Node* temp=Head;

        while(temp!=NULL){
            cout<<temp->value<<" ";
            temp=temp->next;
        }

        cout<<endl;
    }
};

int main()
{
}