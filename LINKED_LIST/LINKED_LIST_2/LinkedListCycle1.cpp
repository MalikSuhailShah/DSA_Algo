#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value) : val(value), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) // gives that node from where cycle begins if present else gives null
{

    ListNode *slow = head;
    ListNode *fast = head;

    bool flag = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            flag = true;
            break;
        }
    }

    if (flag == true)
    {
        ListNode *temp = head;

        while (temp != slow)
        {
            slow = slow->next;
            temp = temp->next;
        }

        return temp;
    }
    else
    {
        return NULL;
    }
}

bool hasCycle(ListNode *head) // checks whether cycle is present or not
{

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{

    ListNode *head = new ListNode(1);

    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(5);

    // LINKING NODES
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    ListNode *node=new ListNode(0);
    if (hasCycle(head))
        node = detectCycle(head);

    cout << hasCycle(head) << " " << node->val << " ";
}