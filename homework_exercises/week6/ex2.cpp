// Exercise 2: Shortest path
// Given a directed computer network with n nodes (numbered from 1 to n) and m
// edges, your task is to write a program to find the shortest path that has the minimum 
// number of edges between two node X and Y.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countConnectedComponents(int n, vector<pair<int,int>> edges, int X, int Y) {
    vector<vector<int>> graph(n);

    for (auto edge : edges) {
        int x = edge.first - 1;
        int y = edge.second - 1;
        graph[x].push_back(y);
    }

    vector<int> distance(n, -1);
    queue<int> q;
    distance[X-1] = 0;
    q.push(X-1);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    return distance[Y - 1];

}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    int result = countConnectedComponents(n, edges, X, Y);
    cout << result << endl;

    return 0;
}