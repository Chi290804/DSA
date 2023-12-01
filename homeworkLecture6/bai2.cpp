#include "bits/stdc++.h"
using namespace std;

struct edge
{
    int x, y, w;
    edge(int x, int y, int w)
    {
        this->x = x;
        this->y = y;
        this->w = w;
    }
};

int n, m, parent[100000], size[100000];
vector<edge> E;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] == Find(parent[u]);
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if (u == v)
        return false;
    if (size[u] < size[v])
        swap(u, v);

    size[u] += size[v];
    parent[v] = u;
    return true;
}

void Kruskal()
{
    vector<edge> MST;
    int t = MST.size();
    int d = 0;
    sort(E.begin(), E.end(), [](edge x, edge y) -> bool
         { return x.w < y.w; });

    for (edge e : E)
    {
        t = MST.size();
        if (t == n - 1)
            break;
        if (Union(e.x, e.y))
        {
            MST.push_back(e);
            d += e.w;
        }
    }

    if (t < n - 1)
    {
        cout << "Khong lien thong!\n";
    }
    else
    {
        cout << d << endl;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edge e(x, y, w);
        E.push_back(e);
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i, size[i] = 1;
    }
    Kruskal();
}