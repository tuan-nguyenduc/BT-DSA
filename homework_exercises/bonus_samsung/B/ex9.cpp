#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Graph {
private:
    int V;
    unordered_map<int, vector<int>> graph;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    bool isConnected() {
        vector<bool> visited(V, false);

        int i;
        for (i = 0; i < V; ++i) {
            if (graph[i].size() > 0) {
                break;
            }
        }

        if (i == V - 1) {
            return true;
        }

        DFS(i, visited);

        for (int i = 0; i < V; ++i) {
            if (!visited[i] && graph[i].size() > 0) {
                return false;
            }
        }

        return true;
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;

        for (int i : graph[v]) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
    }

    bool isEuler() {
        if (!isConnected()) {
            return false;
        }

        for (int i = 0; i < V; ++i) {
            if (graph[i].size() != outDegree(i)) {
                return false;
            }
        }

        return true;
    }

    int outDegree(int v) {
        return graph[v].size();
    }

    vector<int> findEulerCycle() {
        vector<int> eulerCycle;
        if (!isEuler()) {
            eulerCycle.push_back(-1);
            return eulerCycle;
        }

        int startVertex = 0;
        int currentVertex = startVertex;
        stack<int> stack;
        eulerCycle.push_back(currentVertex);

        while (graph[currentVertex].size() > 0) {
            int nextVertex = graph[currentVertex].back();
            graph[currentVertex].pop_back();
            currentVertex = nextVertex;
            eulerCycle.push_back(currentVertex);
        }

        if (eulerCycle.front() != eulerCycle.back()) {
            eulerCycle.clear();
            eulerCycle.push_back(-1);
        }

        return eulerCycle;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 1);

    vector<int> eulerCycle = g.findEulerCycle();

    cout << "Euler Cycle: ";
    for (int vertex : eulerCycle) {
        if (vertex == -1) {
            cout << "No Euler Cycle exists";
            break;
        }
        cout << vertex << " ";
    }

    return 0;
}