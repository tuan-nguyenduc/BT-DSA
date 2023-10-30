
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (order.size() == n) {
        for (int i : order) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "No valid order" << endl;
    }

    return 0;
}

//Em dung fstream thi bi loi, em chua fix duoc nen de input nhap tay a :((
