#include <iostream>
using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int value) : val(value), next(NULL) {}
};

ListNode *removeNthFromEnd1(ListNode *head, int n)
{

    int len = 0;

    ListNode *temp = head;

    while (temp != NULL)
    {

        len++;
        temp = temp->next;
    }

    if (n == len)
    {
        head = head->next;
        return head;
    }
    int idx = len - n + 1;

    temp = head;

    for (int i = 1; i < idx - 1; i++)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;

    return head;
}

ListNode *removeNthFromEnd2(ListNode *head, int n)
{
    
    ListNode *slow = head;
    ListNode *fast = head;

    for (int i = 1; i <= n + 1; i++)
    {
        if(fast==NULL) return head->next;
            
        fast = fast->next;
    }

    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }

    //deleting targetted node
    
    slow->next=slow->next->next;
    return head;
}

int main()
{

    ListNode *head = new ListNode(1);
    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(5);

    // Linking  Nodes

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    int len = 0;

    int n;
    cout << "Enter the number of node from last:" << endl;
    cin >> n;

    


   

    head = removeNthFromEnd2(head, n);

    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}