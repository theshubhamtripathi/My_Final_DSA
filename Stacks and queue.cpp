Stack is basically a data structure or you can say a container which consists of operatrions like push pop top and all it basically works on the principle of 
LIFO(Last in First Out).

Queue is basically a data structure where it follows FIFO(First in First out) which allows any type of vairbale is like int string and all.

Stack using array :

#include <iostream>
using namespace std;
int arr[100];
int top = -1;
int capacity = 100;

void push(int x) {
    if (top == capacity - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    arr[top] = x;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }
    top--;
}

int peek() {
    if (top == -1) {
        return -1;
    }
    return arr[top];
}

bool isEmpty() {
    if (top == -1) {
        return true;
    }
    return false;
}

int main() {
    push(10);
    push(20);
    push(30);
    cout << peek() << endl;
    pop();
    cout << peek() << endl;
    return 0;
}

Queue using array :

#include <iostream>
using namespace std;

int arr[100];
int front = 0;
int rear = -1;
int capacity = 100;
int current_size = 0;

void enqueue(int x) {
    if (current_size == capacity) {
        cout << "Queue Overflow" << endl;
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = x;
    current_size++;
}

void dequeue() {
    if (current_size == 0) {
        cout << "Queue Underflow" << endl;
        return;
    }
    front = (front + 1) % capacity;
    current_size--;
}

int getFront() {
    if (current_size == 0) {
        return -1;
    }
    return arr[front];
}

bool isEmpty() {
    if (current_size == 0) {
        return true;
    }
    return false;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << getFront() << endl;

    dequeue();
    cout << getFront() << endl;

    return 0;
}

