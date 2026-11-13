//leetcode 138 :- https://leetcode.com/problems/copy-list-with-random-pointer/

#include<iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        // creating deep copy

        Node* dummy = new Node(-1);
        Node* temp = head;
        Node* curr = dummy;
        while (temp != NULL) {
            Node*  a = new Node(temp->val);
            curr->next=a;
            curr=curr->next;
            temp=temp->next;
        }

        Node* duplicate=dummy->next;//head of the deep copy of the linked list

        // making alternate connections
         dummy= new Node(-1);
         Node* temp1=head;
         Node* temp2=duplicate;
         curr=dummy;
         while(temp1){
            curr->next=temp1;
            curr=curr->next;
            temp1=temp1->next;
            curr->next=temp2;
            temp2=temp2->next;
            curr=curr->next;
         }

         // assigning random pointers
        Node* a=dummy -> next;// a will travel the original list
        while(a!=NULL){
           Node * b= a->next;
           if(a->random) b->random=a->random->next;
           a=a->next->next;
        }

         
        //removing alternate connections
         temp=dummy->next;
         Node* d1=new Node(-1);//main Linked LIst
         Node* d2=new Node(-1);//diplictae Linked LIst
         Node* t1=d1;
         Node* t2=d2;
         while(temp!=NULL){
            t1->next=temp;
            temp=temp->next;
            t1=t1->next;
            t2->next=temp;
            temp=temp->next;
            t2=t2->next;
         }
            t1->next=NULL;
            t2->next=NULL;
            return d2->next;
         
        return head; 
    }
};