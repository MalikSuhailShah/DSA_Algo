#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        next = prev = NULL;
        this->val = val;
    }
};

class Deque
{
public:
    Node *head;
    Node *tail;
    int size;

     Deque()
    {
        head = tail = NULL;
        size = 0;
    }

    void push_front(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void push_back(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void pop_front()
    {
        if (size == 0)
        {
            cout << "Deque is empty!!" << endl;
            return;
        }
        else
        {
            head = head->next;
            size--;
            head->prev = NULL;
        }
    }

    void pop_back()
    {
        if (size == 0)
        {
            cout << "Deque is empty!!" << endl;
            return;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
            size--;
        }
    }

    int front()
    {
        if (size == 0)
        {
            cout << "Deque is empty!!" << endl;
            return -1;
        }
        else
        {
            return head->val;
        }
    }

    int back(){
        if(size==0){
            cout<<"Deque is empty!!"<<endl;
            return -1;
        }
        else{
            return tail->val;
        }
    }

    int Size(){
        return size;
    }

    bool empty(){
        if(size==0) return true;
        else return false;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Deque q;
    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_back(40);
    q.push_back(50);
    q.push_back(70);
    q.push_back(80);
    q.display();
    q.push_front(90);
    q.display();
    q.pop_back();
    q.pop_back();
    q.display();
    q.pop_front();
    q.display();
    cout<<q.Size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

}