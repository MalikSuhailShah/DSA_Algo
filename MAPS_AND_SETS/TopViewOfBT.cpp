#include <iostream>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    // constructor
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void TopView(TreeNode *root)
{
    queue<pair<TreeNode *, int>> q; //(node,level)
    unordered_map<int, int> mp;     // (level, node->val)

    pair<TreeNode *, int> r;
    r.first = root;
    r.second = 0;

    q.push(r);

    while (q.size() > 0)
    {
        TreeNode *temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if (mp.find(level) == mp.end())
        {
            mp[level] = temp->val;
        }
        if (temp->left != NULL)
        {
            pair<TreeNode *, int> p;
            p.first = temp->left;
            p.second = level - 1;
            q.push(p);
        }
        if (temp->right != NULL)
        {
            pair<TreeNode *, int> p;
            p.first = temp->right;
            p.second = level + 1;
            q.push(p);
        }
    }

    int minIdx = INT_MAX;
    int maxIdx = INT_MIN;
    for (auto ele : mp)
    {
        int level = ele.first;
        minIdx = min(minIdx, level);
        maxIdx = max(maxIdx, level);
    }

    for (int i = minIdx; i <= maxIdx; i++)
    {
        cout << mp[i] << " ";
    }
}

int main()
{

    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    TreeNode *root = a;
    TopView(root);
}