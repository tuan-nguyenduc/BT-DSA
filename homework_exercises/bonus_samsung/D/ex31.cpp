#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(vector<Edge>& edges, int V, int src, vector<int>& dist) {
    dist[src] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
}

void updateGraphWeights(vector<Edge>& edges, vector<int>& pi) {
    for (auto& edge : edges) {
        edge.weight += pi[edge.src] - pi[edge.dest];
    }
}

void dijkstra(vector<Edge>& edges, int V, int src, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    minHeap.push({0, src});

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        int weight = minHeap.top().first;
        minHeap.pop();

        if (weight > dist[u]) continue;

        for (const auto& edge : edges) {
            int v = edge.dest;
            int newDist = dist[u] + edge.weight;
            if (dist[v] > newDist) {
                dist[v] = newDist;
                minHeap.push({dist[v], v});
            }
        }
    }
}

void findAllShortestPaths(vector<Edge>& edges, int V, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    bellmanFord(edges, V, src, dist);

    updateGraphWeights(edges, dist);

    vector<int> dijkstraDist(V, INF);
    for (int i = 0; i < V; ++i) {
        dijkstra(edges, V, i, dijkstraDist);
        cout << "Shortest path fom " << src << " to " << i << ":\n";
        for (int j = 0; j < V; ++j) {
            cout << "Distance to " << j << ": " << dijkstraDist[j] << endl;
        }
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {{0, 1, 2}, {1, 2, -1}, {2, 3, 1}, {3, 0, -4}};

    int sourceVertex = 0;
    findAllShortestPaths(edges, V, sourceVertex);

    return 0;
}
