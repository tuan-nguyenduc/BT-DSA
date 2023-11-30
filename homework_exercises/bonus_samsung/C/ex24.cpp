#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int weight;
    int u, v;

    Edge(int w, int x, int y) : weight(w), u(x), v(y) {}
};

class TreeNode {
public:
    int vertex;
    TreeNode* next;
    TreeNode* prev;

    TreeNode(int v) : vertex(v), next(nullptr), prev(nullptr) {}
};

class Graph {
public:
    Graph(int n) : n(n), parent(n, nullptr), firstNode(n, nullptr), lastNode(n, nullptr) {}

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
                        mergeTrees(uSet, vSet);
                    }
                }
            }
        }

        return mstEdges;
    }

private:
    int n;
    vector<Edge> edges;
    vector<TreeNode*> parent;
    vector<TreeNode*> firstNode;
    vector<TreeNode*> lastNode;

    int findSet(int i) {
        if (parent[i] == nullptr) return i;
        return parent[i]->vertex;
    }

    void mergeTrees(int u, int v) {
        if (lastNode[u] == nullptr) {
            parent[u] = new TreeNode(u);
            lastNode[u] = parent[u];
        }

        if (lastNode[v] == nullptr) {
            parent[v] = new TreeNode(v);
            lastNode[v] = parent[v];
        }

        lastNode[u]->next = firstNode[v];
        firstNode[v]->prev = lastNode[u];

        lastNode[v]->next = firstNode[u];
        firstNode[u]->prev = lastNode[v];

        lastNode[u] = lastNode[v];
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
