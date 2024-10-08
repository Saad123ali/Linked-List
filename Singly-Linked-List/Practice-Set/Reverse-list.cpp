//  Reverse the singly linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class Linked
{
private:
    Node *head;

public:
    Linked() : head(NULL) {}

    void append(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // function to reverse the list
    void reverse()
    {
        Node *prevNode = NULL;
        Node *currNode = head;
        Node *next = NULL;

        while (currNode != NULL)
        {
            next = currNode->next;     // store the next node
            currNode->next = prevNode; //  reverse the current node pointer
            prevNode = currNode;       //  move the previous to current node
            currNode = next;           // move the next node
        }
        head = prevNode; // set the head to the new front of list
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~Linked()   //clean up the memory
    {
        Node* currNode = head;
        Node* next = NULL;
        while(currNode != NULL)
        {
            next = currNode->next;
            delete currNode;
            currNode = next;
        }
    }
};


int main()
{
    Linked list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    
    cout << "Original list: ";
    list.display(); // Display original list

    list.reverse(); // Reverse the list
    cout << "Reversed list: ";
    list.display(); // Display reversed list
}

// Output below

// Original list: 1 -> 2 -> 3 -> 4 -> NULL
// Reversed list: 4 -> 3 -> 2 -> 1 -> NULL