/*
Thuật toán BFS không sắp xếp các đỉnh theo thứ tự tô pô,
mà chỉ duyệt qua các đỉnh theo chiều rộng từ đỉnh nguồn.
Đánh dấu các đỉnh theo khoảng cách tăng dần tới đỉnh nguồn
của chúng chỉ là một cách để ghi nhớ khoảng cách từ đỉnh nguồn
tới các đỉnh khác trong quá trình duyệt BFS. Kết quả của thuật
toán BFS không đảm bảo thứ tự tô pô vì nó không xem xét các
quan hệ phụ thuộc giữa các đỉnh trong đồ thị, mà chỉ tập
trung vào việc duyệt qua các đỉnh theo chiều rộng.
*/
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct dinh
{
    int V;
    int dis;
    dinh(int _V, int distance)
    {
        V = _V;
        dis = distance;
    }
};

bool compareDis(dinh &v1, dinh &v2)
{
    return v1.dis < v2.dis;
}

void BFS(vector<vector<int>> &g, int source)
{
    int n = g.size();
    vector<bool> visited(n, false);
    vector<dinh> dinhs;
    queue<dinh> q;

    q.push(dinh(source, 0));
    visited[source] = true;
    while (!q.empty())
    {
        dinh u = q.front();
        q.pop();
        dinhs.push_back(u);

        for (int i : g[u.V])
        {
            if (!visited[i])
            {
                q.push(dinh(i, u.dis + 1));
                visited[i] = true;
            }
        }
    }
    sort(dinhs.begin(), dinhs.end(), compareDis);

    for (dinh &i : dinhs)
    {
        cout << i.V << " ";
    }
}

void DFS(vector<vector<int>> &graph, int v, vector<bool> &visited, stack<int> &result)
{
    visited[v] = true;
    for (int u : graph[v])
    {
        if (!visited[u])
        {
            DFS(graph, u, visited, result);
        }
    }
    result.push(v);
}

vector<int> TopologicalSort(vector<vector<int>> &graph)
{
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    stack<int> result;

    for (int v = 0; v < numVertices; v++)
    {
        if (!visited[v])
        {
            DFS(graph, v, visited, result);
        }
    }

    vector<int> sortedOrder;
    while (!result.empty())
    {
        sortedOrder.push_back(result.top());
        result.pop();
    }

    return sortedOrder;
}

int main()
{
    int numVertices = 6;
    vector<vector<int>> graph(numVertices);
    cout << "BFS:\n";

    // Khởi tạo đồ thị
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1, 4};
    graph[3] = {1, 4, 5};
    graph[4] = {2, 3, 5};
    graph[5] = {3, 4};

    int source = 0; // Đỉnh nguồn

    BFS(graph, source);
    cout << "\nTopo:\n";

    vector<int> sortedOrder = TopologicalSort(graph);
    for (int v : sortedOrder)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}