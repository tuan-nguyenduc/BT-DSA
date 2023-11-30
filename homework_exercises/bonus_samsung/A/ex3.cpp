#include <iostream>
#include <vector>

using namespace std;

int countParallelEdges(const vector<vector<int>>& graph) {
    int V = graph.size();
    int parallelEdges = 0;
    
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] == 1) {
                for (int k = 0; k < V; ++k) {
                    if (k != i && k != j && graph[i][k] == 1 && graph[j][k] == 1) {
                        parallelEdges++;
                    }
                }
            }
        }
    }

    return parallelEdges / 2;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int result = countParallelEdges(graph);
    cout << "Number of parallel edges: " << result << endl;

    return 0;
}
