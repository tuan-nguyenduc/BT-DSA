//implement stack by linked list
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

struct StackByLinkedList {
    Node* top;

    StackByLinkedList() {
        top == NULL;
    }

    void push(int value);
    void pop();
    void peek();
    bool isEmpty();
    void printStack();
};

void StackByLinkedList::push(int data) {
    Node* newNode = new Node(data);
    if (!top) {
        top = newNode;
        return;
    }
    
    newNode->next = top;
    top = newNode;
}

void StackByLinkedList::pop() {
   Node* temp = top;

   if (top == NULL) {
    cout << "Stack is empty.";
   }
   else {
    top = top->next;
    free(temp);
   }
};

void StackByLinkedList::peek() {
    if (top == NULL) {
        cout << "Stack is empty.";
    } else {
        cout << top->value;
    }
}

void StackByLinkedList::printStack() {
    Node* temp = top;

    if (top == NULL) {
        cout << "Stack is empty.";
        return;
    }

    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }

};

bool StackByLinkedList::isEmpty() {
    return top == NULL;
}

int main () {
    StackByLinkedList* stack = new StackByLinkedList();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "push") {
            int value;
            cin >> value;
            stack->push(value);
        }
        else if (command == "pop") {
            stack->pop();
        }
    }
    stack->printStack();
}