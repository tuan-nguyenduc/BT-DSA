#include <iostream>
using namespace std;

#define capacity 100



//implement queue by linked list
struct Node {
    int value;
    Node* next;

    Node (int _value) {
        value = _value;
        next = NULL;
    }
};

struct QueueByLinkedList {
    Node* front;
    Node* rear;

    QueueByLinkedList() {
        front = rear = NULL;
    }

    void enqueue(int value);
    void dequeue();
    void peek();
    bool isFull();
    void printQueue();
};

//time complexity: O(1)
//space complexity: O(1)
void QueueByLinkedList::enqueue(int data) {
    Node* new_node = new Node(data);
    if (rear == NULL) {
       rear = new_node;
       front = rear;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
};

//time complexity: O(1)
//space complexity: O(1)
void QueueByLinkedList::dequeue() {
    Node* temp = front;

    if (front == NULL) {
        cout << "Queue is empty. Cannot dequeue.";
    }

    else if (temp->next != NULL) {
        temp = temp->next;
        free(front);
        front = temp;
    }

    else {
        free(front);
        front = NULL;
        rear = NULL;
    }
}

//time complexity: O(1)
//space complexity: O(1)
void QueueByLinkedList::peek() {
    if (front == NULL) {
        cout << "Queue is empty!";
    }
    else {
        cout << front->value;
    }
}

//time complexity: O(n)
//space complexity: O(1)
void QueueByLinkedList::printQueue() {
    Node* start = front;

    while (start != NULL) {
        cout << start->value << " ";
        start = start->next;
    }
}

//time complexity: O(n)
//space complexity: O(1)
bool QueueByLinkedList::isFull() {
    int length = 0;

    Node* temp = front;

    if (temp == NULL) {
        return false;
    }

    while (temp->next != NULL) {
        length++;
        temp = temp->next;
    }

    if (length == capacity) {
        return true;
    }

    return false;
}

int main() {
    QueueByLinkedList* queue = new QueueByLinkedList();
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