/// leetcode 430 :- https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

#include<iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {

        Node* temp = head;

        while (temp) {
            Node* nxt = temp->next;

            if (temp->child) {
                Node* c = temp->child;
                temp->child = NULL;

                c = flatten(c);// checking for  childs of child

                temp->next = c; // addind child list to the main list
                c->prev = temp;

                while (c->next)
                    c = c->next;// reaching the tail of child list

                c->next = nxt; // connecting the child list with next potion of main list`
                if (nxt)
                    nxt->prev = c;
            }
            temp = temp->next;
        }
        return head;
    }
};