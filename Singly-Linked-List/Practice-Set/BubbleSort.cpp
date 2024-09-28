// sort the linked list in ascending  & descending order using Bubble sort

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

    // Function to perform Ascending sort on the linked list
    void AscendingBubbleSort()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        bool swapped;
        Node *currNode;
        Node *lastNode = NULL;

        do
        {
            swapped = false;
            currNode = head;
            while (currNode->next != lastNode)
            {
                if (currNode->data > currNode->next->data)
                {
                    int temp = currNode->data;
                    currNode->data = currNode->next->data;
                    currNode->next->data = temp;
                    swapped = true;
                }
                currNode = currNode->next;
            }
            lastNode = currNode;
        } while (swapped);
    }

    // Function to perform Descending sort on the linked list
    void DescendingBubbleSort()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        bool swapped;
        Node *currNode;
        Node *lastNode = NULL;

        do
        {
            swapped = false;
            currNode = head;
            while (currNode->next != lastNode)
            {
                if (currNode->data <  currNode->next->data)
                {
                    int temp = currNode->data;
                    currNode->data = currNode->next->data;
                    currNode->next->data = temp;
                    swapped = true;
                }
                currNode = currNode->next;
            }
            lastNode = currNode;
        } while (swapped);
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

    cout << "Ascending Linked list " << endl;
    linkedList.AscendingBubbleSort();
    linkedList.display();

    cout << "Descending Linked list " << endl;
    linkedList.DescendingBubbleSort();
    linkedList.display();

    return 0;
}

// Output below

// Original Linked List: 3 -> 1 -> 4 -> 2 -> nullptr
// Sorted Linked List: 1 -> 2 -> 3 -> 4 -> nullptr