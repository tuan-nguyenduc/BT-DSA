#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int v;
    vector<vector<int>> adj;
    vector<int> indegree;

    Graph(int vertices) : v(vertices), adj(vertices), indegree(vertices, 0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        indegree[v]++;
    }

    void topoSort() {
        queue<int> q;
        for (int i = 0; i < v; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int current_vertex = q.front();
            q.pop();
            cout << current_vertex << " "; 

            for (int neighbor : adj[current_vertex]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 5);

    cout << "Topo sort: ";
    g.topoSort();

    return 0;
}
