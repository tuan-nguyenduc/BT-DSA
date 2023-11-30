#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<vector<bool>>& edge_connected, int u, int parent) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(graph, visited, edge_connected, v, u);
        } else if (v != parent) {
            edge_connected[u][v] = edge_connected[v][u] = true;
        }
    }
}

bool is_edge_connected(vector<vector<int>>& graph) {
    int num_vertices = graph.size();
    vector<bool> visited(num_vertices, false);
    vector<vector<bool>> edge_connected(num_vertices, vector<bool>(num_vertices, false));

    dfs(graph, visited, edge_connected, 0, -1);

    for (int i = 0; i < num_vertices; ++i) {
        for (int j = 0; j < num_vertices; ++j) {
            if (!edge_connected[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2, 4, 5},
        {3, 5},
        {3, 4}
    };

    bool result = is_edge_connected(graph);
    cout << "Edge connected: " << (result ? "yes" : "no") << endl;

    return 0;
}
