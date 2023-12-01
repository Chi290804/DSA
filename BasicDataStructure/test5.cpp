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

    pair<int, int> findEdgeToRemove(Graph g, int n)
    {
        pair<int, int> lastEdge;
        for (int i = 0; i < n; i++)
        {
            for (int neighbor : l[i])
            {
                int temp = neighbor;
                l[i].erase(find(l[i].begin(), l[i].end(), neighbor));
                l[neighbor].erase(find(l[neighbor].begin(), l[neighbor].end(), i));
                if (!cycle)
                {
                    lastEdge = make_pair(i, neighbor);
                }
                l[i].push_back(temp);
                l[neighbor].push_back(i);
            }
        }

        return lastEdge;
    }
};

int main()
{
    int n;
    cin >> n;
    Graph g(1000);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u  , v);
    }
    g.DFS(0);
    pair<int, int> edgeToRemove = g.findEdgeToRemove(g, n);
    cout << edgeToRemove.first - 1 << " " << edgeToRemove.second << endl;
    return 0;
}