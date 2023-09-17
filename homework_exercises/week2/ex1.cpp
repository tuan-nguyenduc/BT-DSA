// Given a list A of n integer numbers, your task is to write a program to 
// count the number of pairs (i,j) that A[i]=A[j].
#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j ++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
    }

    cout << count;
}