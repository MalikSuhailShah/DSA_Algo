// LeetCode 2326 :- https://leetcode.com/problems/spiral-matrix-iv/submissions/2129785140/

#include<iostream>
#include<vector>
using namespace std;


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> v(m , vector<int> (n,-1));
        int minr =0, minc =0, maxc=n-1, maxr = m-1;
        ListNode* temp = head;
        while(temp!=NULL){
            for(int j = minc ;j<=maxc && temp!=NULL;j++){
                v[minr][j] = temp->val;
                temp = temp -> next;
            }
            minr++;

            for(int j = minr;j<=maxr && temp!=NULL;j++){
                v[j][maxc] = temp->val;
                temp = temp ->next;
            }
            maxc--;

            for(int j = maxc; j>=minc && temp!=NULL; j--){
                v[maxr][j] = temp ->val;
                temp  = temp -> next;
            }
            maxr--;

            for(int j = maxr; j>=minr && temp!=NULL; j--){
                v[j][minc] = temp -> val;
                temp = temp->next;
            }
            minc++;
        }

        return v;

        
    }
};