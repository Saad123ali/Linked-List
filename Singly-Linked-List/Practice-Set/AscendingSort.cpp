
// sort the linked list in ascending order using selection sort

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
        next = NULL;
    }
};

class Linked
{
private:
    Node *head;

public:
    Linked() : head(NULL) {}

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Function to perform selection sort on the linked list
    void AscendingSort()
    {
        Node* currNode = head;
        
        if(currNode == NULL || currNode->next == NULL)
        {
            return;
        }

        while (currNode != NULL)
        {
            Node* minNode = currNode;
            Node* nextNode = currNode->next;

            while(nextNode != NULL)
            {
                if(nextNode->data < minNode->data)
                {
                    minNode = nextNode;
                }
                nextNode = nextNode->next;
            }

            if(minNode != currNode)
            {
                int temp = currNode->data;
                currNode->data = minNode->data;
                minNode->data = temp;
            }
            currNode = currNode->next;
        }
        
    }
};

int main()
{
    Linked linkedList;

    // Insert nodes into the linked list
    linkedList.insert(3);
    linkedList.insert(1);
    linkedList.insert(4);
    linkedList.insert(2);

    cout << "Original Linked List: ";
    linkedList.display();

    // Sort the linked list
    linkedList.AscendingSort();

    cout << "Sorted Linked List: ";
    linkedList.display();

    return 0;
}

// Output below

// Original Linked List: 3 -> 1 -> 4 -> 2 -> nullptr
// Sorted Linked List: 1 -> 2 -> 3 -> 4 -> nullptr  