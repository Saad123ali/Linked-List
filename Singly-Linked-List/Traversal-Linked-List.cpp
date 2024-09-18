// Traversal the linked list of nodes
#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};

int main()
{
    Node* n = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);

    n->next = n1;
    n1->next = n2;

    Node* temp = n;
    while (temp != nullptr)
    {
        cout<<temp->val <<"->";
        temp = temp->next;
    }
    
    return 0;
}