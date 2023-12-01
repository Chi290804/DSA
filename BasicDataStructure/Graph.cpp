#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int v;
    list<int> *l;
    bool visited[1000] = {false};
    /* memset (visited, false,sizeof(visited)); */
public:
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

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << ": ";
            for (int x : l[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    void DFS(int u)
    {
        visited[u] = true;
        for (int a : l[u])
        {
            if (!visited[a])
            {
                DFS(a);
            }
        }
    }

    void BFS(int u)
    {
        bool visited1[v];
        queue<int> f;
        visited1[u-1] = true;
        f.push(u-1);
        while (!f.empty())
        {
            int cur = f.front();
            f.pop();
            cout << cur << " ";
            for (int k : l[cur])
            {
                if (!visited1[k])
                {
                    f.push(k);
                    visited1[k] = true;
                }
            }
        }
    }

    int ConnectedComponent()
    {
        reset();
        int t = 0;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                t++;
                DFS(i);
            }
        }
       return t;
    }

    void Path(int n, int u) {
        
    }

    void reset()
    {
        memset(visited, false, sizeof(visited));
    }
};

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    Graph g(5);
    while (m != 0)
    {
        cin >> x >> y;
        g.addEdge(x-1,y-1);
        m--;
    }
    g.print();
    cout << g.connectedComponents();
}