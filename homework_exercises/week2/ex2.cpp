#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

struct Linkedlist {
    Node* head;

    Linkedlist() {
        head = NULL;
    }

    void insertNode(int position, int value);
    void deleteNode(int position);
    void printList();
};

void Linkedlist::insertNode(int position, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
    }
    Node* count_node = head;
    int count = 0;

    while (count_node != NULL) {
        count++;
        count_node = count_node->next;
    }

    if (position < 0 || position > count) {
        cout << "Position is not valid!" << endl;
        return;
    }

    Node* temp = head;
    
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    Node* nextNode = temp->next;
    temp->next = newNode;
    newNode->next = nextNode;

}

void Linkedlist::deleteNode(int position) {


    if (head == NULL || head->next == NULL) {
        head = NULL;
    }
    Node* count_node = head;
    int count = 0;

    while (count_node != NULL) {
        count++;
        count_node = count_node->next;
    }
    if (position < 0 || position > count) {
        cout << "Position is not valid!" << endl;
        return;
    }

    if (position == 0) {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        return;
    }

    if (position == count) {
        cout << count << endl;
        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* deleteNode = temp->next;
        temp->next = NULL;
        delete deleteNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}
void Linkedlist::printList()
{
    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    //cout << "List: ";
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

int main () {
    Linkedlist* list = new Linkedlist();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            int position, value;
            cin >> position >> value;
            list->insertNode(position, value);
        } else if (command == "delete") {
            int position;
            cin >> position;
            list->deleteNode(position);
        }
    }

    list->printList();

}