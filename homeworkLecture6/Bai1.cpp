#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> adj[100000];
bool visited[100000];
stack<int> st;

void reset()
{
    memset(visited, false, sizeof(visited));
}

vector<int> d[100000];
int mx = 0;
void DFS(int u, int degree)
{
    visited[u] = true;
    mx = max(mx, degree);
    d[degree].push_back(u);
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v, degree + 1);
        }
    }

    st.push(u);
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS(i, 0);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    reset();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i, 0);
        }
    }

    for (int i = 0; i <= mx; i++)
    {
        for (auto it : d[i])
        {
            cout << it << " ";
        }
    }

    return 0;
}