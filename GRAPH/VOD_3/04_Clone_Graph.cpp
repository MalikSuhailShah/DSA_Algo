// Leetcode 133

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> Neighbours;

    Node()
    {
        val = 0;
        Neighbours = vector<Node *>();
    }

    Node(int value)
    {
        this->val = value;
      //  Neighbours = _neighbour;
    }
};

vector<Node *> nodeRegister;

void dfs(Node *actual, Node *clone)
{
    for (auto Neighbour : actual->Neighbours)
    {
        if (not nodeRegister[Neighbour->val])
            {
                Node* newNode = new Node(Neighbour->val);
                nodeRegister[newNode->val] = newNode;
                clone->Neighbours.push_back(newNode);

                dfs(Neighbour, newNode);
            }
        else
            {
                clone->Neighbours.push_back(nodeRegister[Neighbour->val]);
            }
    }
}

Node *cloneGraph(Node *node)
{

    if (node == NULL)
        return NULL;

    Node *clone = new Node(node->val);

    nodeRegister.resize(110, NULL); // this array contains ref to the created nodes

    nodeRegister[clone->val] = clone; // clone->val  is basically an index at which ref of clone is stored

    dfs(node, clone);

    return clone;
}
int main()
{
}