#include <iostream>
using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int value) : val(value), next(NULL) {}
};

int main()
{

    ListNode *head = new ListNode(10); /// head Node
    ListNode *b = new ListNode(20);
    ListNode *c = new ListNode(30);
    ListNode *d = new ListNode(40);

    // Linking Nodes
    head->next = b;
    b->next = c;
    c->next = d;

    int len = 0;

    ListNode *temp = head;

    // calculating length of the List

    // 2 PASS SOLUTION
    // while(temp!=NULL){
    //     len++;
    //     temp=temp->next;
    // }

    // int midIdx=len/2;

    // ListNode* mid=head;

    // for(int i=1;i<=midIdx;i++){

    //     mid=mid->next;

    // }
    // temp=mid;

    // SINGLE pASS SOLUTION

    ListNode *slow = head;

    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;

        fast = fast->next->next;
    }

    temp=slow;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}