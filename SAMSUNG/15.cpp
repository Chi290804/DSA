#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> TopologicalSort(vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<int> indegree(numVertices, 0);

    for (int v = 0; v < numVertices; v++) {
        for (int u : graph[v]) {
            indegree[u]++;
        }
    }

    queue<int> q;
    for (int v = 0; v < numVertices; v++) {
        if (indegree[v] == 0) {
            q.push(v);
        }
    }

    vector<int> sortedOrder;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        sortedOrder.push_back(v);

        for (int u : graph[v]) {
            indegree[u]--;
            if (indegree[u] == 0) {
                q.push(u);
            }
        }
    }

    return sortedOrder;
}

int main() {
    int numVertices, numEdges;
    cout << "Nhap so luong dinh: ";
    cin >> numVertices;
    cout << "Nhap so luong canh: ";
    cin >> numEdges;

    vector<vector<int>> graph(numVertices);
    cout << "Nhap cac canh cua do thi:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cout << "Canh thu " << i + 1 << ": ";
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> sortedOrder = TopologicalSort(graph);

    cout << "Thu tu sap xep topo: ";
    for (int v : sortedOrder) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}