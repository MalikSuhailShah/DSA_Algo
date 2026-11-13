// leetcode 23 :- https://leetcode.com/problems/merge-k-sorted-lists/

#include<iostream>
#include<vector>
using namespace std;



 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

       if( lists.size()==0) return NULL;
        
        while (lists.size() > 1) {
            ListNode* a = lists[0];
            lists.erase(lists.begin());

            ListNode* b = lists[0];
             lists.erase(lists.begin());
            ListNode* c = mergeTwoLists(a, b);
            
            lists.push_back(c);
        }

        return lists[0];
    }
};