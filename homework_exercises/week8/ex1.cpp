#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

bool compareItems (const Item a, const Item b) {
    return a.profit > b.profit;
}

double greedy(int w, vector<Item>& items) {
    double total = 0.0;
    int remainingCapacity = w;

    for (Item& item : items) {
        if (remainingCapacity == 0) {
            break;
        }
        if (item.weight <= remainingCapacity) {
            total += item.profit;
            remainingCapacity -= item.weight;
        }
    }
    return total;
}

int main() {
    int n, w;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> w;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the weight and profit of item " << i << ": ";
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = items[i].profit / items[i].weight;
    }

    sort(items.begin(), items.end(), compareItems);

    double maxProfit = greedy(w, items);

    cout << "Max profit: " << maxProfit << endl;

    return 0;
}