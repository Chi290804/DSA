#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& graph, int v, vector<bool>& visited, stack<int>& result) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            DFS(graph, u, visited, result);
        }
    }
    result.push(v);
}

vector<int> TopologicalSort(vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    stack<int> result;

    for (int v = 0; v < numVertices; v++) {
        if (!visited[v]) {
            DFS(graph, v, visited, result);
        }
    }

    vector<int> sortedOrder;
    while (!result.empty()) {
        sortedOrder.push_back(result.top());
        result.pop();
    }

    return sortedOrder;
}

bool hasUniqueTopologicalOrder(vector<vector<int>>& graph) {
    vector<int> sortedOrder = TopologicalSort(graph);
    int n = sortedOrder.size();

    for (int i = 0; i < n - 1; i++) {
        int u = sortedOrder[i];
        int v = sortedOrder[i + 1];

        bool connected = false;
        for (int neighbor : graph[u]) {
            if (neighbor == v) {
                connected = true;
                break;
            }
        }

        if (!connected) {
            return false;
        }
    }

    return true;
}

int main() {
    int numVertices = 6;
    vector<vector<int>> graph(numVertices);

    // Khởi tạo đồ thị
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1, 4};
    graph[3] = {1, 4, 5};
    graph[4] = {2, 3, 5};
    graph[5] = {3, 4};

    bool hasUniqueOrder = hasUniqueTopologicalOrder(graph);

    if (hasUniqueOrder) {
        cout << "Co thu tu topo duy nhat" << endl;
    } else {
        cout << "Khong co thu tu topo duy nhat" << endl;
    }

    return 0;
}