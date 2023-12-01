#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> mine;

int Prim(vector<vector<mine>> &graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    priority_queue<mine, vector<mine>, greater<mine>> priQueue;
    int min = 0;
    int source = 0;
    priQueue.push(make_pair(0, source));

    while(!priQueue.empty()) {
        int u = priQueue.top().second;
        int cost = priQueue.top().first;
        priQueue.pop();
        if(visited[u])
        continue;
        visited[u] = true;
        min += cost;

        for (auto&i:graph[u]) {
            int v = i.first;
            int weight = i.second;
            if (!visited[v]) {
                priQueue.push(make_pair(weight, v));
            }
        }
    }
    return min;
}



typedef pair<int, pair<int, int>> edge;

int find(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent, parent[x]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int kruskalMST(vector<edge>& edges, int numVertices) {
    sort(edges.begin(), edges.end());

    vector<int> parent(numVertices);
    vector<int> rank(numVertices, 0);
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    int minCost = 0;
    int numEdges = 0;

    for (auto& e : edges) {
        int weight = e.first;
        int u = e.second.first;
        int v = e.second.second;

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU != rootV) {
            minCost += weight;
            unionSet(parent, rank, rootU, rootV);
            numEdges++;

            if (numEdges == numVertices - 1)
                break;
        }
    }

    return minCost;
}

int main() {
        int numVertices, numEdges;
    cout << "Nhap so luong dinh: ";
    cin >> numVertices;
    cout << "Nhap so luong canh: ";
    cin >> numEdges;

    vector<vector<mine>> graph(numVertices);
    vector<edge> edges(numEdges);

    cout << "Nhap cac canh cua do thi (u, v, w):\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cout << "Canh thu " << i + 1 << ": ";
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
        edges[i] = make_pair(w, make_pair(u, v));
    }

    int minCost1 = Prim(graph, numVertices);
    int minCost2 = kruskalMST(edges, numVertices);
    cout << "Tong trong so cua rung bao trum nho nhat: " << minCost1 << " " << minCost2 <<endl;

    return 0;
}