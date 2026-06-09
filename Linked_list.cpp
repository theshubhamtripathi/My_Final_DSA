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

depending on the system memory space used can be different depemnd on 32 bit system or 64 bit system 

Difference:
Node is the actual object (the house). It contains the real data and takes up a large block of memory.
Node* is a pointer (the house address). It is just a small 8-byte variable that stores the memory location of where that Node is sitting in RAM.

First elemnt will be alwasy head 

Node* covertarr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Simple traversal
void printLinkedList(Node* head) {
    // Start from the head of the list
    Node* temp = head;

    // Loop until temp reaches the end (nullptr)
    while (temp != nullptr) {
        // Process the current node's data
        cout << temp->data << " -> ";
        
        // Move the pointer to the next node
        temp = temp->next;
    }
    
    cout << "NULL" << endl;
}

Node* removehead(Node* head) {
    if (head == nullptr) return nullptr; // Use nullptr in modern C++
    
    Node* temp = head;
    head = temp->next; // Move head first
    delete temp;       // Free the old head
    
    return head;
}

we do Node* temp = head becaue we need head so we keep it safe by making a copy of it and doing all the operation based on that copy

Node* removetail(Node* head){
    Node* temp = head;
    if(head == nullptr || head->next == nullptr) return nullptr;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* removeatanyk(Node* head,int k){
    if(head == nullptr) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int c = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        c++;
        if(k==c){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeatanyel(Node* head,int el){
    if(head == nullptr) return head;
    if(head->data == el){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(temp->data == el){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* inserth(Node* head,int val){
    Node* temp = new Node(val,head);
    return temp;
}

Node* insertattail(Node* head,int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newnode = new Node(val);
    temp->next = newnode;
    return head;
}

Node* insertatanyposition(Node* head,int el,int k){
    if(head == nullptr){
        if(k==1){
            return new Node(el);
        } 
        else{
            return head;
        }
    }
    if(k==1) return new Node(el,head);
    int c = 0;
    Node* temp = head;
    while(temp!=nullptr){
        c++;
        if(c == k-1){
            Node* x = new Node(el,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertatanyvalue(Node* head,int el,int val){
    if(head == nullptr){
        return nullptr;
    }
    if(head->data == val) return new Node(el,head);
    Node* temp = head;
    while(temp->next!=nullptr){
        if(temp->next->data == val){
            Node* x = new Node(el,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}


leetcode 297
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = nullptr;
        while(node != nullptr && node->next != nullptr){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        delete node;
    }
};




