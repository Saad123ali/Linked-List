# Linked List

A **Linked List** is a dynamic data structure consisting of a sequence of elements, known as **nodes**, where each node contains two parts:

- **Data**: The actual value or data element.
- **Pointer (or reference)**: A reference or pointer to the next node in the sequence.

Unlike arrays, where elements are stored in contiguous memory locations, linked lists store elements in non-contiguous memory locations. Each node points to the next one, creating a chain-like structure. This allows for efficient insertion and deletion of elements without needing to shift the entire structure, as would be necessary in arrays.

## Key Characteristics:

- **Dynamic Size**: The size of a linked list can grow or shrink dynamically, depending on the number of elements (nodes) added or removed.
- **Non-Contiguous Memory**: Nodes are not stored in consecutive memory locations, making memory allocation more flexible.
- **Pointers**: Each node in a linked list points to the next node, creating a chain of nodes.

## Types of Linked Lists:

1. **Singly Linked List**: Each node points to the next node in the list, and the last node points to `null`, indicating the end of the list.
2. **Doubly Linked List**: Each node has two pointers—one pointing to the next node and one to the previous node.
3. **Circular Linked List**: The last node points back to the first node, forming a circle.

## Advantages:

- **Dynamic Size**: Linked lists can dynamically adjust their size as elements are added or removed.
- **Efficient Insertions/Deletions**: Insertions and deletions can be performed efficiently, especially when dealing with large datasets, without the need to shift elements as in arrays.

## Disadvantages:

- **Memory Overhead**: Each node requires extra memory for the pointer/reference to the next node.
- **Sequential Access**: Unlike arrays, linked lists do not allow direct access to an element by index, requiring traversal of the list to find elements.

## Common Operations:

- **Insertion**: Adding elements at the beginning, middle, or end of the list.
- **Deletion**: Removing elements from any position in the list.
- **Traversal**: Accessing all elements in the list one by one.
- **Searching**: Finding an element within the list.

Linked lists are widely used in scenarios where dynamic memory management and efficient insertions/deletions are required. They are fundamental in many computer science algorithms and applications.
