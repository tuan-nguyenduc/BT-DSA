#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dynamic(int w, vector<int>& weights, vector<int>& profits, int n) {
    vector<vector<int>> dp(n+1, vector<int>(w + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], profits[i - 1] + dp[i - 1][j - weights[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

int main() {
    int n, w;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter the capacity: ";
    cin >> w;

    vector<int> weights(n);
    vector<int> profits(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the weight and profit of item " << i << ": ";
        cin >> weights[i] >> profits[i];
    }

    int maxProfit = dynamic(w, weights, profits, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;

}