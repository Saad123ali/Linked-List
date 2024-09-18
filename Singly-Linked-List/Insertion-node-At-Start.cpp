#include <iostream>
using namespace std;

class Node // Node class to represent each node in the list
{
public:
    int val;
    Node *next;

    Node(int data) // Constructor to initialize the node
    {
        val = data;
        next = nullptr;
    }
};

/// @brief 
class LinkedList // LinkedList class to manage the linked list
{
private:
    Node *head;

public:

    
    LinkedList() // Constructor to initialize an empty list
    {
        head = nullptr;
    }

    void insertAtBeginning(int val)  // Function to insert a node at the beginning of the list
    {
        Node *new_node = new Node(val);

        if (head == nullptr)  // If head is empty then new node is inserted
        {
            head = new_node;
        }
        else  // Otherwise, point the new node to the current head and update head
        {
            new_node->next = head;
            head = new_node;
        }
    }

    void display()  // Function to display the list
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    list.insertAtBeginning(2);
    list.display();
    list.insertAtBeginning(1);
    list.display();
    list.insertAtBeginning(4);
    list.display();
    return 0;
}

//Output of the code below
// 2->NULL
// 1->2->NULL
// 4->1->2->NULL