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



    // Delete the last node
    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is already empty!" << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            cout << "Last node deleted. List is now empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Last node deleted." << endl;
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

    list.deleteEnd();
    cout << "After deleting last node: ";
    list.display();
    // Testing deletion on empty list
    cout << "\nTesting deletion on empty list:\n";
    list.deleteEnd();

    return 0;
}

// outputs Below
// Original List: 10 -> 20 -> 30 -> 40 -> NULL     
// Last node deleted.
// After deleting last node: 10 -> 20 -> 30 -> NULL

// Testing deletion on empty list:
// Last node deleted.