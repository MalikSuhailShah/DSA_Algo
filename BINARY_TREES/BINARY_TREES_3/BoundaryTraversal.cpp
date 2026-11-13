#include <iostream>
#include <climits>
#include <queue>
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

TreeNode *ConstructBT(int arr[], int n)
{
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(arr[0]);
    q.push(root);

    int i = 1, j = 2;

    while (i<n && q.size())
    {
        TreeNode *temp = q.front();
        q.pop();

        TreeNode *l, *r;

        if(arr[i]!=INT_MIN) l=new TreeNode(arr[i]);
        else l=NULL;

        if(j<n && arr[j]!=INT_MIN) r=new TreeNode(arr[j]);
        else r=NULL;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        temp->left=l;
        temp->right=r;

        i+=2;
        j+=2;
    }

    return root;
}

void nthlevel(TreeNode *root, int curr,int level)
{
    if (root == NULL)
        return;

    if (curr==level)
    {
        cout << root->val << " ";
        return;
    }
    nthlevel(root->left, curr+1, level );
    nthlevel(root->right, curr+1, level);
}

int levels(TreeNode *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + max(levels(root->left), levels(root->right));
}

void LevelOrder(TreeNode *root)
{
    int n = levels(root);
    for (int i = 1; i <= n; i++)
    {
        nthlevel(root,1,i);
        cout<<endl;
    }
   }

void LeftBoundary(TreeNode* root){
    if(root==NULL) return;
    if(root->right==NULL && root->left==NULL) return; 
    cout<<root->val<<" ";
    LeftBoundary(root->left);
    if(root->left==NULL) LeftBoundary(root->right);
}   

void leafBoundary(TreeNode* root){
    if(root==NULL) return ;
    if(root->left==NULL && root->right==NULL) cout<<root->val<<" ";
    leafBoundary(root->left);
    leafBoundary(root->right);
}

void rightBoundary(TreeNode* root){
    if(root==NULL) return;
    if(root->right==NULL && root->left==NULL) return; 
    rightBoundary(root->right);
    if(root->right==NULL) rightBoundary(root->left);
    cout<<root->val<<" ";
}
void BoundaryTraversal(TreeNode* root){
    if(root==NULL) return;
    LeftBoundary(root);
    leafBoundary(root);
    rightBoundary(root->right);

}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11,INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode *root = ConstructBT(arr, n);

    BoundaryTraversal(root);
}