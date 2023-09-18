//Implement Stack using 2 queues

#include <iostream>
#include <queue>
using namespace std;

struct Stack {
    queue<int> q, temp;

    void push(int value);
    void pop();
    int top();
    void printStack();
};


void Stack::push(int value) {
    temp.push(value);

    while (!q.empty()) {
        temp.push(q.front());
        q.pop();
    }

    queue<int> swap_queue = q;
    q = temp;
    temp = swap_queue;
}

void Stack::pop() {
    if (q.empty()) {
        return;
    }
    q.pop();
}

void Stack::printStack() {
    queue<int> new_queue = q;

    while (!new_queue.empty()) {
        cout << new_queue.front() << " ";
        new_queue.pop();
    }
}

int Stack::top() {
    if (q.empty()) {
        return -1;
    }
    
    return q.front();
}

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.push(4);
    stack.printStack();




}