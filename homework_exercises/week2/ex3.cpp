#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node *previous;

    Node() {
        value = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
        previous = NULL;
    }
};

struct DoublyLinkedList {
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertNode(int value);
    void count_triplets();
    void printList();
};

void DoublyLinkedList::insertNode(int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    newNode->previous = temp;
    temp->next = newNode;

};

void DoublyLinkedList::printList() {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }

};

void DoublyLinkedList::count_triplets() {
    Node* count_node = head;
    int count = 0;
    while (count_node != NULL) {
        count++;
        count_node = count_node->next;
    }

    if (count < 3) {
        cout << "List must have at least 3 node to count!";
        return;
    }

    Node* temp = head;
    int result = 0;

    for (int i = 0; i < count; i++) {
        if (temp->previous != NULL && temp->next != NULL) {
            if (temp->previous->value + temp->value + temp->next->value == 0) {
                result++;
            }
        }
        temp = temp->next;
    }

    cout << result;
};



int main () {
    DoublyLinkedList* list = new DoublyLinkedList();
    int n;
    cin >> n;
    int value;

    for (int i = 0; i < n; i++) {
        cin >> value;
        list->insertNode(value);
    }
    //list->printList();
    cout << endl;
    list->count_triplets();
}