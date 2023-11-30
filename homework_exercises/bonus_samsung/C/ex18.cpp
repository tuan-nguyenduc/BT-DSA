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

    vector<pair<int, int>> reverseDeleteMST() {
        vector<pair<int, int>> mst;
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight > b.weight;
        });

        for (const auto& edge : edges) {
            mst.push_back({edge.u, edge.v});

            if (!isConnected(mst)) {
                mst.pop_back();
            }
        }

        return mst;
    }

private:
    vector<Edge> edges;

    bool isConnected(const vector<pair<int, int>>& mst) {
        vector<int> parent(mst.size() * 2, -1);

        for (const auto& edge : mst) {
            int uSet = find(parent, edge.first);
            int vSet = find(parent, edge.second);

            if (uSet == vSet) {
                return false;
            }

            unionSets(parent, uSet, vSet);
        }

        return true;
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

    vector<pair<int, int>> resultReverseDelete = graph.reverseDeleteMST();

    cout << "MST:" << endl;
    for (const auto& edge : resultReverseDelete) {
        cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    cout << endl;

    return 0;
}
