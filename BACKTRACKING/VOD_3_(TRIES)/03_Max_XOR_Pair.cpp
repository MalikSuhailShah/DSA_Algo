// leetcode 421 https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node {
public:
    Node* left = NULL; // 0 bit
    Node* right = NULL; // 1 bit
};

class Solution {
public:
    void insert( Node* head , int value) {
        Node* curr = head;

        for (int i = 31; i >= 0; i--) {
            int bit = (value >> i) & 1;

            if (bit == 1) {
                if (curr->right == NULL) {
                    Node* temp = new Node();
                    curr->right = temp;
                }
                curr = curr->right;
            } else {
                if (curr->left == NULL) {
                    Node* temp = new Node();
                    curr->left = temp;
                }
                curr = curr->left;
            }
        }
    }
    // compares the incoming data with the data already inserted in trie
    int MaxXorPair(Node* head, int value)
    {
        Node* curr = head;
        int curr_xor = 0;

        for(int i = 31; i>=0; i--){
            int bit = (value >> i) & 1;

            if(bit == 1){
                if(curr -> left){
                    curr = curr -> left;
                    curr_xor += (1<<i);
                }
                else{
                    curr = curr -> right;
                }
            }
            else {
                if(curr -> right){
                    curr = curr -> right;
                    curr_xor += (1<<i);
                }
                else{
                    curr = curr -> left;
                }
            }
        }

        return curr_xor;
    }

    int findMaximumXOR(vector<int>& nums) { 
        Node* head = new Node();
        insert(head, nums[0]);

        int ans = INT_MIN;

        for(int i=0;i<nums.size();i++){
            ans = max(ans,MaxXorPair(head,nums[i]));
            insert(head,nums[i]);
        }

        return ans;
    }
};

int main (){

}