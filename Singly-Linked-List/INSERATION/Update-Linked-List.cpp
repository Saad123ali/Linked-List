#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    { // Constructor to initialize the node
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

    void insertNode(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void updateNode(int pos, int newVal)
    {
        // Check if the list is empty
        if (head == nullptr)
        {
            cout << "The list is empty. No nodes to update.\n";
            return;
        }

        if (pos < 0)
        {
            cout << "Position must be non-negative\n";
            return;
        }

        Node *temp = head;
        int currPosition = 0;

        while (temp != nullptr)
        {
            if (currPosition == pos)
            {
                cout << "Old Value: " << temp->data << "\n";
                temp->data = newVal;
                cout << "New Value: " << temp->data << " at position " << pos << "\n";
                return; // Exit after updating
            }
            temp = temp->next;
            currPosition++;
        }

        cout << "Position out of range\n";
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main()
{
    LinkedList list;

    // Inserting nodes into the linked list
    list.insertNode(10);
    list.insertNode(20);
    list.insertNode(30);
    list.insertNode(40);

    cout << "Original Linked List: ";
    list.display();

    int position, newValue;
    cout << "Enter position to update: ";
    cin >> position;
    cout << "Enter new value: ";
    cin >> newValue;

    // Updating a node at the specified position
    list.updateNode(position, newValue);

    cout << "Updated Linked List: ";
    list.display();

    return 0;
}

// Output of the code below
//  Original Linked List: 10 -> 20 -> 30 -> 40 -> null
//  Enter position to update: 2
//  Enter new value: 23
//  Old Value : 30
//  New Value : 23 at position 2
//  Position out of range
//  Updated Linked List: 10 -> 20 -> 23 -> 40 -> null