#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int weight;
    int u, v;

    Edge(int w, int x, int y) : weight(w), u(x), v(y) {}
};

class Graph {
public:
    Graph(int n) : n(n), parent(n, -1) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({weight, u, v});
    }

    vector<pair<int, int>> boruvka() {
        vector<pair<int, int>> mstEdges;
        while (mstEdges.size() < n - 1) {
            vector<Edge> minEdges(n, Edge(INT_MAX, -1, -1));
            for (const auto& edge : edges) {
                int uSet = findSet(edge.u);
                int vSet = findSet(edge.v);

                if (uSet != vSet && edge.weight < minEdges[uSet].weight) {
                    minEdges[uSet] = edge;
                }
            }

            for (const auto& edge : minEdges) {
                if (edge.weight != INT_MAX) {
                    int uSet = findSet(edge.u);
                    int vSet = findSet(edge.v);

                    if (uSet != vSet) {
                        mstEdges.push_back({edge.u, edge.v});
                        unionSets(uSet, vSet);
                    }
                }
            }
        }

        return mstEdges;
    }

private:
    int n;
    vector<Edge> edges;
    vector<int> parent;

    int findSet(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = findSet(parent[i]);
    }

    void unionSets(int u, int v) {
        int uSet = findSet(u);
        int vSet = findSet(v);

        if (uSet != vSet) {
            parent[uSet] = vSet;
        }
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 3, 3);
    graph.addEdge(0, 3, 4);
    graph.addEdge(1, 3, 5);

    vector<pair<int, int>> mstBoruvka = graph.boruvka();

    cout << "MST :" << endl;
    for (const auto& edge : mstBoruvka) {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }

    return 0;
}
