// Exercise 1: Connected components
// Given an undirected computer network with n nodes (numbered from 1 to n) and m
// edges, your task is to write a program to calculate the number of connected 
// components.

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int countConnectedComponents(int n, vector<pair<int, int>> edges) {
    vector<vector<int>> graph(n);
    
    for (auto edge : edges) {
        int x = edge.first - 1;
        int y = edge.second - 1;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<bool> visited(n, false);
    int connectedComponents = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            connectedComponents++;
        }
    }

    return connectedComponents;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
       edges.push_back({x, y});
    }

    int result = countConnectedComponents(n, edges);
    cout << result << endl;
    return 0;
}