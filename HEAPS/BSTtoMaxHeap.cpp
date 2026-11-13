#include <iostream>
#include <vector>
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

void Inorder(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    Inorder(root->right, arr);
    arr.push_back(root->val);
    Inorder(root->left, arr);
}

void MakeHeap(TreeNode *root, vector<int> &arr, int &idx)
{
    if (root == NULL)
        return;

    root->val = arr[idx++];
    MakeHeap(root->left, arr, idx);
    MakeHeap(root->right, arr, idx);
}

void display(TreeNode *root)
{

    queue<TreeNode *> q;
    q.push(root);
    while (q.size())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

void print(vector<int> & arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    TreeNode *a = new TreeNode(10);
    TreeNode *b = new TreeNode(5);
    TreeNode *c = new TreeNode(16);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(8);
    TreeNode *f = new TreeNode(12);
    TreeNode *g = new TreeNode(20);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    vector<int> arr; // this array stores reverse inorder of the binary search  tree
    Inorder(a, arr);

    print(arr);

    display(a);
    int i=0;
    MakeHeap(a, arr, i);  // BST is converted to heap here
    cout<<endl;
    display(a);
}