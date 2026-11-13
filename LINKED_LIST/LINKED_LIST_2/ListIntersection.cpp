#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value) : val(value), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

    int lenA = 0;
    int lenB = 0;

    ListNode *tempA = headA;

    ListNode *tempB = headB;

    while (tempA != NULL)
    {
        lenA++;
        tempA = tempA->next;
    }

    while (tempB != NULL)
    {
        lenB++;
        tempB = tempB->next;
    }

    tempA = headA;
    tempB = headB;

    if (lenA > lenB)
    {
        int diff = lenA - lenB;

        for (int i = 1; i <= diff; i++)
        {
            tempA = tempA->next;
        }

        while (tempA != tempB)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }
    else
    {
        int diff = lenB - lenA;

        for (int i = 1; i <= diff; i++)
        {
            tempB = tempB->next;
        }

        while (tempA != tempB)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }
}

int main()
{

    ListNode *headA = new ListNode(1);

    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(5);

    // LINKING NODES
    headA->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    ListNode *headB = new ListNode(10);
    ListNode *e = new ListNode(8);

    // LINKING NODES
    headB->next=e;
    e->next=b;

    ListNode* Intersected = getIntersectionNode(headA, headB);

    cout<<Intersected->val<<" ";
}