Stack is basically a data structure or you can say a container which consists of operatrions like push pop top and all it basically works on the principle of 
LIFO(Last in First Out).

Queue is basically a data structure where it follows FIFO(First in First out) which allows any type of vairbale is like int string and all.

Stack using array :
#include <iostream>
using namespace std;

class MyStack {
private:
    int arr[100];
    int top;
    int capacity;

public:
    MyStack() {
        top = -1;
        capacity = 100;
    }

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
};

int main() {
    MyStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    return 0;
}

Queue using array :
#include <iostream>
using namespace std;

class MyQueue {
private:
    int arr[100];
    int front;
    int rear;
    int capacity;
    int current_size;

public:
    MyQueue() {
        front = 0;
        rear = -1;
        capacity = 100;
        current_size = 0;
    }

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
};

int main() {
    MyQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.getFront() << endl;

    q.dequeue();
    cout << q.getFront() << endl;

    return 0;
}


Implementing stack using linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == NULL) {
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        if (top == NULL) {
            return true;
        }
        return false;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    return 0;
}


Implementing queue using linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == NULL) {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    int getFront() {
        if (front == NULL) {
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        if (front == NULL) {
            return true;
        }
        return false;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.getFront() << endl;

    q.dequeue();
    cout << q.getFront() << endl;

    return 0;
}

Implement stack using queue:
Stack is LIFO(Last in First out) and queue if FIFO(First in First out)
#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        q1.pop();
    }

    int peek() {
        if (q1.empty()) {
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        if (q1.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    StackUsingQueue s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    return 0;
}

Implementing queue using stack :
#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
private:
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int getFront() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool isEmpty() {
        if (s1.empty() && s2.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    QueueUsingStack q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.getFront() << endl;

    q.dequeue();
    cout << q.getFront() << endl;

    return 0;
}

Leetcode 20 valid parenthesis 
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char current = s[i];

            if (current == '(' || current == '{' || current == '[') {
                st.push(current);
            }
            else {
                if (st.empty()) {
                    return false;
                }

                char ch = st.top();
                st.pop();

                if (current == ')' && ch == '(') {
                    continue;
                }
                else if (current == '}' && ch == '{') {
                    continue;
                }
                else if (current == ']' && ch == '[') {
                    continue;
                }
                else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

leetcode 155 min stack 
class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {
        long long val = value;

        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else {
            if (val >= mini) {
                st.push(val);
            }
            else {
                st.push(2 * val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if (st.empty()) {
            return;
        }

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2 * mini - x;
        }
    }
    
    int top() {
        long long x = st.top();

        if (x < mini) {
            return mini;
        }
        return x;
    }
    
    int getMin() {
        return mini;
    }
};

Prefix, Infix, and Postfix Conversion 

1. What is an Operand?
An Operand is the actual data or value in the expression. It is the object that is being modified, counted, or calculated.
 
2. What is an Operator?
An Operator is the symbol that tells you what mathematical action or operation to perform on the operands.    

Infix: The operator sits inside (between) the operands (e.g., A + B). This is how humans write math.
Prefix: The operator sits before (pre) the operands (e.g., + A B).
Postfix: The operator sits after (post) the operands (e.g., A B +).    

Infix to postfix conversion :

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getPriority(char ch) {
    if (ch == '^') {
        return 3;
    }
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char current = s[i];

        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9')) {
            result = result + current;
        }
        else if (current == '(') {
            st.push(current);
        }
        else if (current == ')') {
            while (!st.empty() && st.top() != '(') {
                result = result + st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && getPriority(current) <= getPriority(st.top())) {
                result = result + st.top();
                st.pop();
            }
            st.push(current);
        }
    }

    while (!st.empty()) {
        result = result + st.top();
        st.pop();
    }

    return result;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}

Infix to prefix :
1.) Reverse the infix
2.) Infix to postfix
3.) Reverse that answer 

#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // Used for reversing strings

using namespace std;

// Helper function to define operator precedence
int getPriority(char ch) {
    if (ch == '^') {
        return 3;
    }
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

// Standard Infix to Postfix conversion logic
string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char current = s[i];

        // If character is an operand, add it to output
        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9')) {
            result += current;
        }
        // If character is '(', push it to stack
        else if (current == '(') {
            st.push(current);
        }
        // If character is ')', pop and output until '(' is found
        else if (current == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop(); // Remove '(' from stack
            }
        }
        // If an operator is encountered
        else {
            while (!st.empty() && getPriority(current) <= getPriority(st.top())) {
                // Special handling for right-associative operator '^'
                if (current == '^' && st.top() == '^') {
                    break; 
                }
                result += st.top();
                st.pop();
            }
            st.push(current);
        }
    }

    // Pop all remaining operators from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

// Core function to convert Infix to Prefix
string infixToPrefix(string infix) {
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Step 2: Swap opening and closing parentheses
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Step 3: Get the postfix of the modified reversed expression
    string postfix = infixToPostfix(infix);

    // Step 4: Reverse the postfix result to get the final prefix expression
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    
    cout << "Infix Expression:  " << infix << endl;
    cout << "Prefix Expression: " << infixToPrefix(infix) << endl;
    
    return 0;
}


//Leetcode 225
//There are 2 methods to solve this question first by 2 queues and 2nd by using only one queue.

//We can also solve this question one queue also this is the ioslo up question for this concept 
class MyStack {
public:

    //queue<int> q1;
    //queue<int> q2;

    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // swap(q1,q2);

        q.push(x);
        int n = q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        // int r = q1.front();
        // q1.pop();
        // return r;

        int r = q.front();
        q.pop();
        return r;
    }
    
    int top() {
        // return q1.front();

        return q.front();
    }
    
    bool empty() {
        // return q1.empty();

        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */






























































































































