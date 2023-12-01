#include <bits/stdc++.h>
#include <set>
using namespace std;

class Graph
{
private:
    int v;
    list<int> *l;
    bool visited[10000] = {false};

public:
    Graph(int d)
    {
        v = d;
        l = new list<int>[d];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void DFS(int u)
    {
        visited[u] = true;
        for (int a : l[u])
        {
            if (!visited[a])
            {
                visited[a] = true;
                DFS(a);
            }
        }
    }

    int connectedComponents()
    {
        int t = 0;
        memset(visited, false, sizeof(visited));
        for (int i=0; i<v;i++)
        {
            if (!visited[i])
            {
                DFS(i);
                t++;
            }
        }
        return t;
    }

};

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    Graph g(n);
    while (m != 0)
    {
        cin >> x >> y;
        g.addEdge(x-1,y-1);
        m--;
    }
    cout << g.connectedComponents();
}