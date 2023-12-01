/*
Thuật toán n thời gian tuyến tính tính thành phần liên thông mạnh chứa một
đỉnh v cho trước ta sử thuật thuật toán Kosaraju:
    - Tạo một stack rỗng để lưu thứ tự duyệt xong các đỉnh của đồ thị.
      Đỉnh nào sắp xếp xong thì đẩy vào stack
    - Lật ngược hướng của các cạnh trên đồ thị ban
      đầu để thu được đồ thị chuyển vị (transpose graph)
    - Lần lượt lấy các đỉnh trong ngăn xếp và nếu
      đỉnh này được chưa được duyệt trong các thành phần
      liên thông mạnh trước đó thì lấy đỉnh này làm đỉnh
      nguồn và gọi thuật toán DFS (trên đồ thị transpose ở
      bước 2) để in ra các đỉnh trong thành phần liên thông.
*/

#include <bits/stdc++.h>
using namespace std;
int n, m, timer = 0, scc=0, scc1=0;
vector<int> adj[1005], t_adj[1005];
int disc[1005], low[1005];
bool visited[1005], in_stack[1005];
stack<int> st;

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);   // graph
        t_adj[y].push_back(x); // transpose graph
    }
    memset(visited, false, sizeof(visited));
    memset(in_stack, false, sizeof(visited));
}

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            DFS(v);
    }
    st.push(u);
}

void DFSreverse(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : t_adj[u])
    {
        if (!visited[v])
            DFSreverse(v);
    }
}

void Kosaraju()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS(i);
    }
    memset(visited, false, sizeof(visited));
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            scc++;
            cout << "scc" << scc << " : ";
            DFSreverse(node);
            cout << endl;
        }
    }
}

/*
Thuật toán thời gian bậc hai đơn giản để tính các
thành phần liên thông mạnh của một đồ thị có hướng là
thuật toán Tarjan:

*/

void TarjanDFS(int u)
{
    visited[u] = true;
    in_stack[u] = true;
    disc[u] = low[u] = ++timer;
    st.push(u);
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (low[u] == disc[u])
    {
        ++scc1;
        while (st.top() != u)
        {
            cout << st.top() << ' ';
            in_stack[st.top()] = false;
            st.pop();
        }
        cout << st.top() << endl;
        in_stack[st.top()] = false;
        st.pop();
    }
}

int main()
{
    nhap();
    cout << "Kosaraju\n";
    Kosaraju();
    cout<<"\nTarjan\n";
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            TarjanDFS(i);
        }
    }
    cout << scc << endl;
}