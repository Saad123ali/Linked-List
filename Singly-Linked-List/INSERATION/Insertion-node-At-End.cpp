#include <iostream>
using namespace std;

class Node // LinkedList class to manage the linked list
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

class LinkedList // Constructor to initialize an empty list
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int val) // Function to insert a node at the end of the list
    {
        Node *new_node = new Node(val);

        if (head == nullptr) // If head is empty then new node is inserted
        {
            head = new_node;
        }
        else // Otherwise,Traverse to the last node of the list
        {
            Node *temp = head;

            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = new_node; // Set the next of the last node to the new node
        }
    }

    void display() // Function to display the list
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
    list.insertAtEnd(4);
    list.display();
    list.insertAtEnd(3);
    list.display();
    list.insertAtEnd(7);
    list.display();
    return 0;
}

//Output of the code below
//4->NULL      
// 4->3->NULL   
// 4->3->7->NULL