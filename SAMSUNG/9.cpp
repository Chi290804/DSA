#include <bits/stdc++.h>
using namespace std;

bool isConnected(unordered_map<char, vector<char>> &graph, char source, unordered_map<char, bool> &visited)
{
    visited[source] = true;
    for (char i : graph.at(source))
    {
        if (!visited[i])
        {
            isConnected(graph, i, visited);
        }
    }

    for (auto &i : graph)
    {
        if (!visited[i.first])
        {
            return false;
        }
    }
    return true;
}

bool isEqual(unordered_map<char, vector<char>> &graph)
{
    for (auto &i : graph)
    {
        char u = i.first;
        int in = 0;
        int out = i.second.size();

        for (auto &y : graph)
        {
            for (char U : y.second)
            {
                if (U == u)
                {
                    in++;
                }
            }
        }
        if (in != out)
        {
            return false;
        }
    }
    return true;
}

void eulerCycle(unordered_map<char, vector<char>>& graph, char source, vector<char>& cycle) {
    unordered_map<char, vector<char>> t = graph;

    while (!t[source].empty())
    {
        char a = source;
        cycle.push_back(a);
        char nexta = t[a].back();
        t[a].pop_back();
        source = nexta;
    }
    
}

int main() {
        unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'D'}},
        {'B', {'C'}},
        {'C', {'A'}},
        {'D', {'E'}},
        {'E', {'A'}}
    };

    char start_vertex = graph.begin()->first;

    unordered_map<char, bool> visited;
    if (!isConnected(graph, start_vertex, visited) || !isEqual(graph)) {
        cout << "Khong ton tai chu trinh Euler." << endl;
        return 0;
    }

    vector<char> cycle;
    eulerCycle(graph, start_vertex, cycle);

    // In chu trinh Euler
    cout << "Chu trinh Euler: ";
    for (char vertex : cycle) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}