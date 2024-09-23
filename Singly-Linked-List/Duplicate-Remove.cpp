// To solve this problem in C++, we need to iterate through the sorted linked list and remove any duplicate nodes. Since the list is sorted, duplicates will always appear consecutively, which simplifies the process.
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int x) : val(x), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    // Constructor for LinkedList
    LinkedList() : head(nullptr) {}

    // Function to add a new node at the end of the linked list
    void append(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node(value);
        }
    }

    // Function to delete duplicates from the sorted linked list
    void deleteDuplicates()
    {
        Node *current = head;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->val == current->next->val)
            {
                Node *duplicate = current->next;
                current->next = current->next->next; // Skip the duplicate node
                delete duplicate;                    // Free the memory of the duplicate node
            }
            else
            {
                current = current->next; // Move to the next distinct element
            }
        }
    }

    // Function to print the linked list
    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    // Append values to the list
    list.append(1);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(3);

    std::cout << "Original list: ";
    list.printList(); // Output: 1 1 2 3 3

    // Remove duplicates
    list.deleteDuplicates();

    cout << "List after removing duplicates: ";
    list.printList(); // Output: 1 2 3

    return 0;
}


//Output below

// Original list: 1 1 2 3 3 
// List after removing duplicates: 1 2 3 