//Implement Queue using 2 stacks

#include <iostream>
#include <stack>
using namespace std;

struct Queue {
    stack<int> s, temp;

    void enqueue (int value);
    int dequeue();
    int front();
    void printQueue();
};

void Queue::enqueue(int value) {
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    s.push(value);

    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
};

int Queue::dequeue() {
    if (s.empty()) {
        return -1;
    }

    int value = s.top();
    s.pop();
    return value;
}

int Queue::front() {
    if (s.empty()) {
        return -1;
    }
    int value = s.top();
    return value;
}

void Queue::printQueue() {
    stack<int> new_stack = s;
    while (!new_stack.empty()) {
        cout << new_stack.top() << " ";
        new_stack.pop();
    }
}

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.printQueue();
    cout << endl;
    cout << queue.dequeue();
    //cout << queue.front();
}