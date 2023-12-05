#include <bits/stdc++.h>
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
    return e1.weight < e2.weight;
}

void VyssotskyMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result(V - 1);

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    vector<Subset> subsets(V);
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0; // index of the next edge to be added to the result
    int i = 0; // index of the current edge being considered

    while (e < V - 1 && i < E) {
        Edge next_edge = graph.edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << "Minimum Spanning Tree (MST) using Vyssotsky's algorithm:\n";
    for (int i = 0; i < e; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << "\n";
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

    VyssotskyMST(graph);

    return 0;
}