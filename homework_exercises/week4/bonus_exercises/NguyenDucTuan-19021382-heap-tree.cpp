#include<iostream>
using namespace std;

class MaxHeap
{
    int *root;
    int capacity;
    int heap_size;

public:
    MaxHeap(int _capacity) {
        capacity = _capacity;
        root = new int[capacity];
        heap_size = 0;
    }

    int getParent(int i) {
        return (i - 1)/2;
    }

    int getLeftChild(int i) {
        return (2*i + 1);
    }

    int getRightChild(int i) {
        return (2*i + 2);
    }

    void insert(int value) {
        if (heap_size >= capacity) {
            cout << "Heap is full." << endl;
            return;
        }

        int i = heap_size;
        root[i] = value;
        heap_size++;

        while (i != 0 && root[getParent(i)] < root[i]) {
            swap(root[i], root[getParent(i)]);
            i = getParent(i);
        }
    }

    void MaxHeapify(int i) {
        int left = getLeftChild(i);
        int right = getRightChild(i);
        int largest = i;

        if (left < heap_size && root[left] > root[i]) {
            largest = left;
        }
        if (right < heap_size && root[right] > root[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(root[i], root[largest]);
            MaxHeapify(largest);
        }
    }

    int getMaxValue() {
        if (heap_size <= 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        return root[0];
    }

    int getHeapSize() {
        return heap_size;
    }

    int extractMaxValue() {
        if (heap_size <= 0) {
            cout << "Heap is empty." << endl;
            return -1;
        }

        if (heap_size == 1) {
            heap_size--;
            return root[0];
        }

        int max = root[0];
        root[0] = root[heap_size - 1];
        heap_size--;
        
        MaxHeapify(0);

        return max;
    }

    void removeNode(int value) {
        int i;

        for (i = 0; i < heap_size; i++) {
            if (root[i] == value) {
                break;
            }
        }
        if(i == heap_size) {
            cout << "Not found";
            return;
        }

        root[i] = root[heap_size - 1];
        heap_size--;

        while(i > 0 && root[i] > root[getParent(i)]) {
            swap(root[i], root[getParent(i)]);
            i = getParent(i);
        }

        MaxHeapify(i);
    }

    int depth(int data, int i = 0, int currentDepth = 0) {
        if (i >= heap_size) {
            return -1;
        }

        if (root[i] == data) {
            return currentDepth;
        }

        int leftChildIndex = getLeftChild(i);
        int rightChildIndex = getRightChild(i);

        int leftDepth = depth(data, leftChildIndex, currentDepth + 1);
        int rightDepth = depth(data, rightChildIndex, currentDepth + 1);

        if (leftDepth != -1) {
            return leftDepth;
        }

        if (rightDepth != -1) {
            return rightDepth;
        }

        return -1;
    }

    int numOfLeaves(int i = 0) {
        if (i >= heap_size || getLeftChild(i) >= heap_size) {
            return 1;
        }

        int leftLeaves = numOfLeaves(getLeftChild(i));
        int rightLeaves = numOfLeaves(getRightChild(i));

        return leftLeaves + rightLeaves;
    }

    void printHeapTree() {
        for (int i = 0; i < heap_size; i++) {
            cout << root[i] << " ";
        }
        cout << endl;
    }

    int findMaxChild() {
    int maxChildCount = 0;
    int nodeWithMaxChildren = -1;

    for (int i = 0; i < heap_size; i++) {
        int leftChildIndex = getLeftChild(i);
        int rightChildIndex = getRightChild(i);
        int childCount = 0;

        if (leftChildIndex < heap_size && root[leftChildIndex] > root[i]) {
            childCount++;
        }

        if (rightChildIndex < heap_size && root[rightChildIndex] > root[i]) {
            childCount++;
        }

        if (childCount > maxChildCount) {
            maxChildCount = childCount;
            nodeWithMaxChildren = i;
        }
    }

    return nodeWithMaxChildren;
    }

};

int main() {
    MaxHeap maxHeap(10);
    maxHeap.insert(4);
    maxHeap.insert(10);
    maxHeap.insert(8);
    maxHeap.insert(15);
    maxHeap.insert(20);
    maxHeap.insert(12);
    cout << "Max Heap: ";
    maxHeap.printHeapTree();
    cout << "Tree Depth: " << maxHeap.depth(4) << endl;
    cout << "Number of leaves: " << maxHeap.numOfLeaves() << endl;
    cout << "Max child node:" << maxHeap.findMaxChild() << endl;
    cout << "Extracting max: " << maxHeap.extractMaxValue() << endl;
    cout << "Max Heap after extraction: ";
    maxHeap.printHeapTree();

    return 0;
}