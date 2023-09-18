#include <iostream>
using namespace std;

struct Stack {
    int top, capacity;
    int *stack;

    Stack (int _capacity) {
        top = -1;
        capacity = _capacity;
        stack = new int;
    }

    void push(int value);
    void pop();
    void PrintStack();
};

void Stack::push(int value) {
    if (top >= (capacity - 1)) {
        cout << "Stack is full";
        return;
    } else {
        top++;
        stack[top] = value;
    }
};

void Stack::pop() {
    if (top < 0) {
        cout << "Stack is empty!";
        return;
    }
    else {
        top--;
    }
};

void Stack::PrintStack() {
    if (top < 0) {
        cout << "Stack is empty!";
        return;
    }
    for (int i = 0; i <= top; i++) {
        cout << *(stack + i) << " ";
    }

};

int main () {
    Stack* stack = new Stack(1000);
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