//In linked list we store the elements as non contiguous memory not one after another 
1. Memory Structure & AllocationVector (Dynamic Array): Allocates memory in a contiguous block. Elements are stored next to each other in memory.
Linked List: Allocates memory non-contiguously. Each element (node) is scattered in memory and contains the data plus a pointer/reference to the next node.

It is used in browsers typically the tail in c++ is nullptr also in implementing stack and queue 
we cant store memeory location exactly so we store pointers for it in c++ 

Boilerplate:
#include <bits/stdc++.h>
using namespace std;

class Node {
public: // 1. Necessary so main() can access the data
    int data;
    Node* next; //This is a pointer. The * means "this variable stores a memory address." What kind of address? The address of another Node. This is how nodes link to each other.

    // Constructor to create a node with a specific next pointer This constructor lets you create a node and immediately link it to another one. If you pass it a number (data1) and an address (next1), it assigns them to the node's variables.
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor to create a standalone node (points to nothing) This is a second constructor (constructor overloading). If you only give it a number, it assumes this is the last node in the list, so it safely sets next to nullptr (which means "pointing to nothing").
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
}; // 2. Classes must end with a semicolon

int main() {
    // A standard vector to pull data from
    vector<int> arr = {1, 2, 3, 4, 5};

    // 3. Create a new Node in heap memory using the first element of the array
    // 'y' is a pointer that stores the address of this new node
    Node* y = new Node(arr[0]);

    // Access the data using the arrow (->) operator Node* y: Because new allocates memory, it returns a memory address. y is a pointer variable that stores that address. y is not the node itself; y is the address of where the node is living in RAM.
    cout << "The data in the first node is: " << y->data << endl;

    return 0;
}

So basically whta is understood a linked list consist of a class which store the data and the address ie memeory location of next node if next node is empty then make next as nullptr.

  












