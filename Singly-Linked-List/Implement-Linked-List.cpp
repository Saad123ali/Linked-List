#include <iostream>
using namespace std;

class Node
{
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
    Node* n = new Node(2);
    cout<<n->val<<" "<<n->next<<endl;
    return 0;
}
