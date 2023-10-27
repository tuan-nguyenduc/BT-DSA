#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

void dfs (int u, vector<bool>& visited, vector<vector<int>> adjList, stack<int>& s) {
    visited[u] = true;
    for (auto v : adjList[u]) {
        // if (visited[v]) {
        //     cout << "Error: graph contains a cycle";
        //     return;
        // }
        if (!visited[v]) {
            dfs(v, visited, adjList, s);
        }
    }
    s.push(u);
}

int main() {
    ifstream input("jobs.txt");
    int n, m;
    input >> n >> m;

    vector<vector<int>> adjList(n + 1);
    vector<bool> visited(n+1, false);
    stack<int> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        adjList[u].push_back(v);
        }
    input.close();

    vector<int> result(n+1, 0);
    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adjList, s);
        }
    }

    int cnt = 0;
    while (!s.empty()) {
        result[s.top()] = ++cnt; 
        s.pop();
    }

    ofstream output("jobs.out");
    for (int job : result) {
        output << job << endl;
    }
    output.close();

    return 0;
}
