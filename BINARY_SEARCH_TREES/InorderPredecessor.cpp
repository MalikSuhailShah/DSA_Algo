#include <iostream>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode *insertIntoBST(TreeNode *root, int v)
{
    if (root == NULL)
        return new TreeNode(v);
    else if (root->val > v)
    { // go left
        if (root->left == NULL)
        { // attach it here
            root->left = new TreeNode(v);
        }
        else
        {
            insertIntoBST(root->left, v);
        }
    }
    else
    { // root->val<v :go right
        if (root->right == NULL)
        { // attach it here
            root->right = new TreeNode(v);
        }
        else
            insertIntoBST(root->right, v);
    }
    return root;
}

TreeNode* InPredecessor(TreeNode* root,int key){
    if(root==NULL) return NULL;
    TreeNode* prev=root->left;
    while(prev->right!=NULL) prev=prev->right;
    return prev;

}
TreeNode* InSuccessor(TreeNode* root, int key){
    if(root==NULL) return root;
    TreeNode* next=root->right;
    while(next->left!=NULL) next=next->left;
    return next;
}
int main()
{
    TreeNode* root=new TreeNode(10);
    insertIntoBST(root,5);
    insertIntoBST(root,8);
    insertIntoBST(root,2);
    insertIntoBST(root,4);
    insertIntoBST(root,3);
    insertIntoBST(root,20);
    insertIntoBST(root,15);
    insertIntoBST(root,25);
    insertIntoBST(root,12);
    insertIntoBST(root,13);

    TreeNode* pre= InPredecessor(root,10);
    TreeNode* suc=InSuccessor(root,10);

    cout<<pre->val<<" "<<suc->val<<endl;
    

}