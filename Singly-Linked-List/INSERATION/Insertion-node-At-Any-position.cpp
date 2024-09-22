#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtBeginning(int val)
    {
        Node *new_node = new Node(val);

        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }

    void insertAtTail(int val)
    {
        Node *new_node = new Node(val);

        if (head == nullptr)
        {
            head = new_node;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void insertAtPosition(int val, int pos)
    {
        // Handle inserting at the head (position 0)
        if (pos == 0)
        {
            insertAtBeginning(val);
            return; // Exit after inserting at the beginning
        }

        Node *new_node = new Node(val);
        Node *temp = head;
        int currPosition = 0; // Start at position 0

        while (currPosition < pos - 1 && temp != nullptr)
        {
            temp = temp->next;
            currPosition++;
        }

        if (temp == nullptr)
        {
            cout << "Position out of bounds!" << endl;
            delete new_node; // Free memory if the position is invalid
        }
        else
        {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    void display()
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

    list.insertAtBeginning(1); // insert at beginning of list
    list.display();
    list.insertAtBeginning(2); // insert at beginning of list
    list.display();
    list.insertAtTail(4); // insert at tail of list
    list.display();
    list.insertAtPosition(5, 2); // Valid position
    list.display();
    list.insertAtPosition(6, 6); // Invalid position
    list.display();

    return 0;
}

// Output of the code below
//  1->NULL
//  2->1->NULL
//  2->1->4->NULL
//  2->5->1->4->NULL
//  Position out of bounds!