#include<iostream>
#include<climits>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }

};

void display(TreeNode* root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

int sum(TreeNode* root){
    if(root==NULL) return 0;
    else return root->val+sum(root->left)+sum(root->right);
}

int size(TreeNode* root){// size refers to the count of all nodes in the tree

    if(root==NULL) return 0;
    else return 1+size(root->left)+size(root->right);

}

int maxi(TreeNode* root){
    if(root==NULL) return INT_MIN;
    else return max(max(root->val,maxi(root->left)),maxi(root->right));
}

int levels(TreeNode* root){
    if(root==NULL) return 0;
    else return 1+max(levels(root->left),levels(root->right));
}
int main (){

    TreeNode* a=new TreeNode(10);
    TreeNode* b=new TreeNode(20);
    TreeNode* c=new TreeNode(30);
    TreeNode* d=new TreeNode(40);
    TreeNode* e=new TreeNode(50);
    TreeNode* f=new TreeNode(60);
    TreeNode* g=new TreeNode(70);
    //TreeNode* h=new TreeNode(80);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    display(a);
    cout<<endl;
    cout<<sum(a)<<endl;
    cout<<size(a)<<endl;
    cout<<maxi(a)<<endl;
    cout<<levels(a)<<endl;

}