//  Implement a program to find the middle of a Linked List using a two-pointer approach (slow and fast pointer).

// Note: In a singly linked list, we can't move backward

#include <iostream>
using namespace std;

class Node
{
public:
    int data;  
    Node *next; 

    Node(int val)
    {
        data = val;
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

    void insert(int val)
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

    // Function to find the middle element using the two-pointer (slow and fast) approach
    void findMiddle()
    {
        // If the list is empty, print a message and return
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *slow = head; // Slow pointer 
        Node *fast = head; // Fast pointer

        // Move the fast pointer two steps and the slow pointer one step at a time
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        // When the loop ends, the slow pointer will be at the middle of the list
        cout << "The middle element is: " << slow->data << endl;
    }

    void display()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main()
{
    LinkedList list;
    
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    // Display the current linked list
    cout << "Current Linked List: ";
    list.display();

    // Find and display the middle element of the linked list
    list.findMiddle();

    return 0;
}

//Outputs below

// Current Linked List: 1->2->3->4->5->Null
// The middle element is: 3
