#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int weight;
    int u;
    int v;

    Edge(int w, int x, int y) : weight(w), u(x), v(y) {}
};

class Graph {
public:
    void addEdge(int u, int v, int weight) {
        edges.push_back(Edge(weight, u, v));
    }

    vector<pair<int, int>> vyssotsky() {
        vector<pair<int, int>> mst;
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        for (const auto& edge : edges) {
            int weight = edge.weight;
            int u = edge.u;
            int v = edge.v;

            mst.push_back({u, v});

            if (isCyclic(mst)) {
                mst.pop_back();
            }
        }

        return mst;
    }

private:
    vector<Edge> edges;

    bool isCyclic(const vector<pair<int, int>>& mst) {
        vector<int> parent(mst.size() + 1, -1);

        for (const auto& edge : mst) {
            int u = edge.first;
            int v = edge.second;

            int uSet = find(parent, u);
            int vSet = find(parent, v);

            if (uSet == vSet) {
                return true;
            }

            unionSets(parent, uSet, vSet);
        }

        return false;
    }

    int find(const vector<int>& parent, int node) {
        if (parent[node] == -1) {
            return node;
        }
        return find(parent, parent[node]);
    }

    void unionSets(vector<int>& parent, int u, int v) {
        int uSet = find(parent, u);
        int vSet = find(parent, v);

        if (uSet != vSet) {
            parent[uSet] = vSet;
        }
    }
};

int main() {
    Graph graph;
    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 0, 3);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 0, 5);

    vector<pair<int, int>> resultVyssotsky = graph.vyssotsky();

    cout << "MST:" << endl;
    for (const auto& edge : resultVyssotsky) {
        cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    cout << endl;

    return 0;
}
