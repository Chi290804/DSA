#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int v;
    list<int> *l;
    int visited[1000] = {0};
    /* memset (visited, false,sizeof(visited)); */
public:
    bool cycle = false;
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void DFS(int u)
    {
        
        visited[u] = 1;
        for (int a : l[u])
        {
            if (visited[a] == 0)
            {
                DFS(a);
            }
            else if (visited[a] == 1)
                cycle = true;
            
        }
        visited[u] = 2;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(1000);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.DFS(0);
    if (g.cycle == true)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}