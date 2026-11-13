#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        this->val = value;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isMax(TreeNode *root)
{
    if (root == NULL)
        return true;

    if (root->left != NULL && root->val < root->left->val)
        return false;
    if (root->right != NULL && root->val < root->right->val)
        return false;

    return isMax(root->left) && isMax(root->right);
}

int sizeOfTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

bool isCBT(TreeNode *root)
{
    int s = sizeOfTree(root);
    int count = 0;

    queue<TreeNode *> q;
    q.push(root);
    while (count < s)
    {
        TreeNode *temp = q.front();
        q.pop();
        count++;
        if (temp != NULL){
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    while (q.size() > 0)
    {
        TreeNode *temp = q.front();
      
        if (temp != NULL)  return false;
          q.pop();
    }
    return true;
}
int main()
{
    TreeNode *a = new TreeNode(20);
    TreeNode *b = new TreeNode(15);
    TreeNode *c = new TreeNode(10);
    TreeNode *d = new TreeNode(8);
    TreeNode *e = new TreeNode(11);
    TreeNode *f = NULL;
    
     TreeNode *g = new TreeNode(6);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;


    if(isMax(a) && isCBT(a)) cout<<"Given binary Tree is Max Heap!!"<<endl;
    else cout<<"Given Binary Tree is not Max Heap!!"<<endl;
}