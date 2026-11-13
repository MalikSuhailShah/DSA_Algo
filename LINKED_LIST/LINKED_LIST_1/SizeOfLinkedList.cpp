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

int Size(Node *head)
{

    Node *temp = head;
    int n = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        n++;
    }

    return n;
}

void Display(Node *Head)
{
    Node *temp = Head;

    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *a = new Node(10); // this is the first Node of the Linked List=> Head Of the Linked List
    Node *e = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);

    // Linking Nodes oF Linked List
    a->next = b;
    b->next = c;
    c->next = d;

    int s = Size(a);

    cout << "The Length of the linked List is:" << s << endl;

    Display(a);
}