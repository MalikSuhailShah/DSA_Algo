//leetcode 21 :- https://leetcode.com/problems/merge-two-sorted-lists/submissions/2129802671/

#include<iostream>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode* farzi = new ListNode(100);
        ListNode* newHead = farzi;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                farzi->next = temp1;
                temp1 = temp1->next;
                farzi = farzi->next;
            } else {
                farzi->next = temp2;
                temp2 = temp2->next;
                farzi = farzi->next;
            }
        }

        if (temp1)
            farzi->next = temp1;

        if (temp2)
            farzi->next = temp2;

        return newHead->next;
    }
};