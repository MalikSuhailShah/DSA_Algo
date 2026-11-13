// leetcode 61 :- https://leetcode.com/problems/rotate-list/description/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        int n = 0;
        ListNode *slow = head;

        while (slow != NULL)
        {
            n++;
            slow = slow->next;
        }

        if (n <= 1)
            return head;

        slow = head;
        ListNode *fast = head;
        k = k % n;
        for (int i = 1; i <= k; i++)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = NULL;

        return head;
    }
};