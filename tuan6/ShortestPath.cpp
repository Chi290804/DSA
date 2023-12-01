#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int v;
    list<int> *l;
    bool visited[10000] = {false};
    int parent[100000];

public:
    Graph(int d)
    {
        v = d;
        l = new list<int>[v+1];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void BFS(int x)
    {
        queue<int> s;
        s.push(x);
        visited[x] = true;
        while (!s.empty())
        {
            int u = s.front();
            s.pop();
            for (int i : l[u])
            {
                if (!visited[i])
                {
                    s.push(i);
                    visited[i] = true;
                    parent[i] = u;
                }
            }
        }
    }
    void shortestPath(int x, int y)
    {
        BFS(x);
        int t = 0;

        if (!visited[y]) // Tai sao, code sai o dau?
        {
            cout << "Khong co duong di\n";
        }
        else
        {
            vector<int> res;
            while (y != x)
            {
                res.push_back(y);
                y = parent[y];
            }
            res.push_back(x);
            for (int i = 0; i < res.size(); i++)
            {
                if (res[i] != x)
                    t++;
            }
            cout << t;
        }
    }
};

int main()
{
    int m, n, x, y, a, b;
    cin >> n >> m >> x >> y;
    Graph g(n);
    while (m != 0)
    {
        cin >> a >> b;
        g.addEdge(a, b);
        m--;
    }

    g.shortestPath(x, y);
}
