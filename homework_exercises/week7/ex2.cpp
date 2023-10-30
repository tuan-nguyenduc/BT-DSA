#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, d;
};

bool compareEdges(const Edge &a, const Edge &b)
{
    return a.d < b.d;
}

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionNodes(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v)
    {
        if (rank[u] < rank[v])
        {
            swap(u, v);
        }

        parent[v] = u;
        if (rank[u] == rank[v])
        {
            rank[u]++;
        }
    }
}

int main()
{
    ifstream input("connection.txt");
    ofstream output("connection.out");

    int n, m;
    input >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
    {
        input >> edges[i].u >> edges[i].v >> edges[i].d;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    vector<Edge> selectedEdges;

    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int d = edges[i].d;

        if (findParent(u, parent) != findParent(v, parent))
        {
            totalCost += d;
            selectedEdges.push_back(edges[i]);
            unionNodes(u, v, parent, rank);
        }
    }

    output << totalCost << endl;

    for (const Edge &edge : selectedEdges)
    {
        output << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    input.close();
    output.close();

    return 0;
}
