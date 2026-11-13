// leetcode 234 :- https://leetcode.com/problems/palindrome-linked-list/

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        ListNode *curr = head, *prev = NULL, *nxt = NULL;

        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *s = new ListNode(100);
        ListNode *temps = s;
        ListNode *temp = head;
        while (temp)
        {
            temps->next = new ListNode(temp->val); // deeep copy
            temp = temp->next;
            temps = temps->next;
        }

        s = reverseList(s->next);
        temp = head;
        temps = s;
        while (temp)
        {
            if (temp->val != temps->val)
                return false;

            temp = temp->next;
            temps = temps->next;
        }

        return true;
    }
};