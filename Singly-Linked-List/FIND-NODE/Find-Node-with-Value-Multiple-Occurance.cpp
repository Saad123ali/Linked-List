#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
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

    // Add a new node at the end of the list
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display the linked list
    void display()
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Delete the head node
    void deleteHead()
    {
        if (!head)
        {
            cout << "List is already empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Head deleted." << endl;
    }

    // Delete the last node
    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List is already empty!" << endl;
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
            cout << "Last node deleted. List is now empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Last node deleted." << endl;
    }

    // Delete a node at a specific position
    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (position == 0)
        {
            deleteHead();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp->next; ++i)
        {
            temp = temp->next;
        }
        if (!temp || !temp->next)
        {
            cout << "Position out of range!" << endl;
            return;
        }
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Node at position " << position << " deleted." << endl;
    }
    // Find all nodes by value
    void findNode(int value)
    {
        if (!head)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        int position = 0;
        bool found = false; // Flag to check if any node is found

        while (temp)
        {
            if (temp->data == value)
            {
                cout << "Node with value " << value << " found at position " << position << "." << endl;
                found = true;
            }
            temp = temp->next;
            ++position;
        }
        if (!found)
        {
            cout << "Node with value " << value << " not found." << endl;
        }
    }
};

int main()
{
    LinkedList list;


    list.append(10);
    list.append(20);
    list.append(20);  // Adding duplicate
    list.append(30);
    list.append(20);  // Adding another duplicate
    list.append(40);

    cout << "Original List: ";
    list.display();

    list.findNode(20);  // Should find multiple occurrences
    list.findNode(100); // Should not find anything

    return 0;
}

// Outputs below 
// Original List: 10 -> 20 -> 20 -> 30 -> 20 -> 40 -> NULL
// Node with value 20 found at position 1.
// Node with value 20 found at position 2.
// Node with value 20 found at position 4.
// Node with value 100 not found.
