#include <iostream>
using namespace std;

//implement queue by array
struct QueueByArray {
    int front, rear, capacity;
    int* queue;
    QueueByArray (int _capacity) {
        front = rear = 0;
        capacity = _capacity;
        queue = new int;
    }

    void enqueue(int value);
    void dequeue();
    void peek();
    bool isFull();
    void printQueue();
};

//time complexity: O(1)
//space complexity: O(1)
void QueueByArray::enqueue(int value) {
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

//time complexity: O(1)
//space complexity: O(1)
void QueueByArray::dequeue() {
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

//time complexity: O(1)
//space complexity: O(1)
void QueueByArray::peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!";
        return;
    }
    cout << queue[front];
}

bool QueueByArray::isFull()
    {
        if (rear == capacity - 1)
            return 1;
 
        return 0;
    }


//time complexity: O(n)
//space complexity: O(1)
void QueueByArray::printQueue() {
    if (front == rear) {
        cout << "Queue is empty!";
        return;
    }
    for (int i = front; i < rear; i++) {
        cout << *(queue + i) << " ";
    }
}

int main () {
    QueueByArray* queue = new QueueByArray(100);
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
    cout << endl;
    queue->peek();
}