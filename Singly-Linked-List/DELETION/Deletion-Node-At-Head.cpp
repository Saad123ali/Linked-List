#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Add a new node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display the linked list
    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Delete the head node
    void deleteHead() {
        if (!head) {
            cout << "List is already empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Head deleted." << endl;
    }


};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    cout << "Original List: ";
    list.display();

    list.deleteHead();
    cout << "After deleting head: ";
    list.display();

    // Testing deletion on empty list
    cout << "\nTesting deletion on empty list:\n";
    list.deleteHead();

    return 0;
}

// Outputs below 

// Original List: 10 -> 20 -> 30 -> 40 -> NULL
// Head deleted.
// After deleting head: 20 -> 30 -> 40 -> NULL

// Testing deletion on empty list:
// Head deleted.