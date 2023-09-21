#include <iostream>
using namespace std;

//Algorithm 1
unsigned long long compute1(int n) {
    unsigned long long num = 2;
    if (n == 0) {
        return 1;
    }
    for (int i = 1; i < n; i++) {
        num = num*2;
    }
    return num;
}

//Algorithm 2
unsigned long long compute2(int n) {
   int num = 2;
   if (n == 0) {
    return 1;
   }
   return 2*compute2(n-1);
}


int main() {
    int n;
    cin >> n;
    cout << compute2(n);
}

//The time complexity of the algorithm 1 is O(n)
//The space complexity of the algorithm 1 is O(1)
//The time complexity of the algorithm 2 is O(n)
//The space complexity of the algorithm 2 is O(n)