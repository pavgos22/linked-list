# Bidirectional linked list implementation C/C++

This project implements a doubly linked list in C++ with support for multiple iterators, allowing flexible manipulation and traversal of the list.

## 1. Doubly Linked List Structure

### Node Structure
Each `Node` contains:
- A `data` field of type `unsigned long long int`.
- A pointer to the next node (`next`).
- A pointer to the previous node (`prev`).

### CreateNode Function
The `CreateNode` function creates a new node with the specified data, initializing the `next` and `prev` pointers to `NULL`.

## 2. Linked List Operations

### PushFront Function
`PushFront` adds a new node with the specified value before a given node in the list. If the list is empty, it sets the new node as both `head` and `tail`.

### PushBack Function
`PushBack` adds a new node with the specified value after a given node in the list. If the list is empty, it sets the new node as both `head` and `tail`.

### Delete Function
The `Delete` function removes a specified node from the list and updates the `head` and `tail` pointers if necessary. It also updates any iterators pointing to the deleted node to point to the next or previous node.

## 3. Iterator Mechanism

### Multiple Iterators
The code supports up to 10 iterators, managed through an array `Node* iterator[ITERATOR]`, where `ITERATOR` is defined as 10.

### Init Iterator
An iterator can be initialized to point to the `head`, `tail`, or another iterator's current position in the list.

### Increment/Decrement Iterator
The iterator can be moved forward (`asc`) or backward (`desc`) through the list, pointing to the next or previous node, respectively.

## 4. Command Handling

### InsertCommand Function
The `InsertCommand` function interprets and executes commands read from the input to manipulate the linked list.

### Commands

- **"i"**: Initializes an iterator. It can be set to the `head`, `tail`, or another iterator's position.
- **".A" and "A."**: Insert elements to the left (before) or right (after) a node. The insertion can occur at the beginning (`BEG`), end (`END`), or at a specific iterator's position.
- **"+" and "-"**: Move an iterator forward or backward by one node.
- **"P"**: Print the entire list (`ALL`) or the data at the current iterator's position.
- **"R"**: Remove nodes from the list at the beginning (`BEG`), end (`END`), or the node pointed to by a specific iterator.

</br>

## Example Usage

To utilize this doubly linked list and iterator system, input commands according to the supported operations. The system will respond by modifying the linked list accordingly.

---

This implementation allows for dynamic and flexible manipulation of a doubly linked list, providing an intuitive mechanism for managing multiple positions within the list using iterators.
