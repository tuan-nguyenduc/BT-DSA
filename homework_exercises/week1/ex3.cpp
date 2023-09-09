#include <iostream>
using namespace std;

// Selection sort
void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        swap(a[min_index], a[i]);
    }
}

// Bubble sort
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

// Insertion sort
void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j = j - 1; 
        }
        a[j+1] = key;
    }
}


void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++) {
        cout << arr[i] << " ";
    }

}

int main() {
    int arr[] = {2, 1, 10, 6, 3 ,8, 7, 13, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    //selection_sort(arr, n);
    //bubble_sort(arr, n);
    insertion_sort(arr, n);
    printArray(arr, n);

}