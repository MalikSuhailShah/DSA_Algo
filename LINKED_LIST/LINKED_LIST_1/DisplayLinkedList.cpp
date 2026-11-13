#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

void Display(Node *Head)
{

    Node *temp = Head;

    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void RecDisplay(Node *Head)
{
    if (Head == NULL)
        return;

    cout << Head->value << " ";
    RecDisplay(Head->next);
}

void ReverseDisplay(Node *Head)
{
    if (Head == NULL)
        return;

    ReverseDisplay(Head->next);
    cout << Head->value << " ";
}

int main()
{
    Node *a = new Node(10); // this is the first Node of the Linked List=> Head Of the Linked List
    Node *e = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);

    // Linking Nodes oF Linked List
    a->next = e;
    e->next = b;
    b->next = c;
    c->next = d;

    RecDisplay(a);
    cout << endl;

    ReverseDisplay(a);
}