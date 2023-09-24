#include <iostream>
using namespace std;

//implement stack by array
struct StackByArray {
    int top, capacity;
    int *stack;

    StackByArray (int _capacity) {
        top = -1;
        capacity = _capacity;
        stack = new int;
    }

    void push(int value);
    void pop();
    void peek();
    bool isEmpty();
    void PrintStack();
};

//time complexity: O(1)
//space complexity: O(1)
void StackByArray::push(int value) {
    if (top >= (capacity - 1)) {
        cout << "Stack is full";
        return;
    } else {
        top++;
        stack[top] = value;
    }
};

//time complexity: O(1)
//space complexity: O(1)
void StackByArray::pop() {
    if (top < 0) {
        cout << "Stack is empty!";
        return;
    }
    else {
        top--;
    }
};

//time complexity: O(n)
//space complexity: O(1)
void StackByArray::PrintStack() {
    if (top < 0) {
        cout << "Stack is empty!";
        return;
    }
    for (int i = 0; i <= top; i++) {
        cout << *(stack + i) << " ";
    }

};

//time complexity: O(1)
//space complexity: O(1)
void StackByArray::peek() {
    if (top < 0) {
        cout << "Stack is empty";
        return;
    }
    else {
        cout << stack[top];
    }
}

//time complexity: O(1)
//space complexity: O(1)
bool StackByArray::isEmpty() {
    return top < 0;
}

int main () {
    StackByArray* stack = new StackByArray(1000);
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
    stack->PrintStack();
}