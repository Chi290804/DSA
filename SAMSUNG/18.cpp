#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

struct Subset {
    int parent;
    int rank;
};

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight > e2.weight;
}

void ReverseDeleteMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result;

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    vector<Subset> subsets(V);
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (const Edge& edge : graph.edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        if (x != y) {
            result.push_back(edge);
            Union(subsets, x, y);
        }
    }

    cout << "Minimum Spanning Tree (MST) using Reverse-Delete algorithm:\n";
    for (const Edge& edge : result) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
    }
}

int main() {
    Graph graph;
    graph.V = 6; // số đỉnh
    graph.E = 10; // số cạnh

    graph.edges = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 4},
        {1, 3, 1},
        {2, 3, 2},
        {3, 4, 3},
        {3, 5, 2},
        {4, 5, 1},
        {2, 4, 1},
        {0, 3, 2}
    };

    ReverseDeleteMST(graph);

    return 0;
}