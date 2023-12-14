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

//Merge sort
void merge(int a[], int const left, int const mid, int const right) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    int leftArray[subArrayOne];
    int rightArray[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++) {
        leftArray[i] = a[left + i];
    }
    for (int j = 0; j < subArrayTwo; j++) {
        rightArray[j] = a[mid + 1 + j];
    }

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;

    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            a[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            a[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        a[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
}

void merge_sort(int a[], int const begin, int const end) {
    if (begin >= end) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    merge_sort(a, begin, mid);
    merge_sort(a, mid + 1, end);
    merge(a, begin, mid, end);
}

//Quick sort
int partition(int a[], int start, int end) {
    int pivot = a[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (a[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(a[pivotIndex], a[start]);

    int i = start;
    int j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (a[i] <= pivot) {
            i++;
        }

        while (a[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(a[i++], a[j--]);
        }
    }
    return pivotIndex;
}

void quick_sort (int a[], int start, int end) {
    if (start >= end) {
        return;
    }

    int p = partition(a, start, end);

    quick_sort(a, start, p - 1);

    quick_sort(a, p + 1, end);
}

//Heap sort
void heapify(int a[], int n, int i) {
    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) {
        largest = l;
    }

    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(a, n , i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);

        heapify(a, i, 0);
    }
}

//Radix sort
int get_max(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void count_sort(int arr[], int n, int exp)
{
	int output[n], i, count[10] = {0};
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
 
void radix_sort(int arr[], int n)
{
	int exp, m;
	m = get_max(arr, n);
 
	for (exp = 1; m/exp > 0; exp *= 10)
		count_sort(arr, n, exp);
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
    //insertion_sort(arr, n);
    //merge_sort(arr, 0, n - 1);
    //quick_sort(arr, 0, n - 1);
    //heap_sort(arr, n);
    radix_sort(&arr[0], n);
    printArray(arr, n);

}