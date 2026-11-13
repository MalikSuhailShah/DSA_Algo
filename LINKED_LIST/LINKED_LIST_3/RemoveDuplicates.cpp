#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value) : val(value), next(NULL) {}
};

ListNode *deleteDuplicates1(ListNode *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->val == temp->next->val)
        {
            temp->next = temp->next->next;
        }
        else
            temp = temp->next;
    }

    return head;
}
ListNode *deleteDuplicates2(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *a = head;
    ListNode *b = head->next;

    while (b != NULL)
    {
        while (b != NULL && a->val == b->val)
        {
            b = b->next;
        }

        a->next = b;
        //for next iteration
        a = b;
        if (b != NULL)
            b = b->next;
    }
}

int main()
{

    ListNode *head = new ListNode(1);

    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);

    // LINKING NODES

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    head = deleteDuplicates1(head);

    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}