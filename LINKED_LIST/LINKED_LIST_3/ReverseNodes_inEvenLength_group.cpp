// leetcode=> 2074 :- https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/

#include<iostream>
using namespace std;


// linked list class
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* nxt = NULL;
        ListNode* prev = NULL;
        while (curr) {
            nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        return prev;
    }

void reversePart(ListNode* head, int left, int right) {

    ListNode* a = head;
    ListNode* b = head;
    ListNode* c = head;
    ListNode* d = NULL;

    int n = 0;
    ListNode* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        n++;
    }

    temp = head;

    for(int i = 1; i <= n; i++) {

        if(i == left - 1)
            a = temp;

        if(i == left)
            b = temp;

        if(i == right)
            c = temp;

        if(i == right + 1)
            d = temp;

        temp = temp->next;
    }

    // Cut the part to be reversed
    c->next = NULL;

    // Reverse b → ... → c
    c = reverse(b);

    // Reconnect
    a->next = c;
    b->next = d;

    return ;
}

    ListNode* reverseEvenLengthGroups(ListNode* head) {
    //     ListNode* temp = head;

    //     int n = 0;

    //     while(temp!=NULL){
    //         temp= temp->next;
    //         n++;
    //     }
    //     temp = head;
    //     int idx = 0;
    //     int windowSize = 1;

    //     while((idx + windowSize)<n){
    //         if((windowSize)%2==0){
    //             int right = windowSize + idx ;
    //             int left = idx+1;
    //             reversePart(head, left, right);
    //         }

    //         idx += windowSize;
    //         windowSize++;
    //     }

    //    int remLen = n - (idx);
    //    if(remLen%2==0){
    //     reversePart(head, idx+1, n);
    //    }

    //    return head;


        // solution => 2
         ListNode* prev = head;
        int gap = 2;

        while (prev->next != NULL) {

            // Start of current group
            ListNode* groupHead = prev->next;
            ListNode* temp = groupHead;

            int count = 0;

            // Find actual number of nodes in this group
            while (temp != NULL && count < gap) {
                temp = temp->next;
                count++;
            }

            // Reverse if actual length is even
            if (count % 2 == 0) {

                ListNode* curr = groupHead;
                ListNode* previous = temp;// node next to last node of group

                // Reverse exactly 'count' nodes
                for (int i = 0; i < count; i++) {
                    ListNode* nextNode = curr->next;

                    curr->next = previous;
                    previous = curr;
                    curr = nextNode;
                }

                // Connect previous part to reversed group
                prev->next = previous;// connect last group to the current one

                // Old group head is now tail
                prev = groupHead;
            }
            else {

                // No reversal: move prev to group tail
                for (int i = 0; i < count; i++) {
                    prev = prev->next;
                }
            }

            gap++;
        }

        return head;
    }
};