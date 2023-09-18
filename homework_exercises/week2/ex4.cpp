#include <iostream>
using namespace std;

struct Queue {
    int front, rear, capacity;
    int* queue;
    Queue (int _capacity) {
        front = rear = 0;
        capacity = _capacity;
        queue = new int;
    }

    void enqueue(int value);
    void dequeue();
    void printQueue();
};

void Queue::enqueue(int value) {
    if (rear == capacity) {
        cout << "Queue is full";
        return;
    }
    else {
        queue[rear] = value;
        rear++;
    }
    return;
};

void Queue::dequeue() {
    if (front == rear) {
        cout << "Queue is empty!";
    }
    else {
        for (int i = 0; i < rear; i++) {
            queue[i] = queue[i+1];
        }
        rear--;
    }
    return;
}

void Queue::printQueue() {
    if (front == rear) {
        cout << "Queue is empty!";
        return;
    }
    for (int i = front; i < rear; i++) {
        cout << *(queue + i) << " ";
    }
}

int main () {
    Queue* queue = new Queue(100);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "enqueue") {
            int value;
            cin >> value;
            queue->enqueue(value);
        }
        else if (command == "dequeue") {
            queue->dequeue();
        }
    }

    queue->printQueue();
}