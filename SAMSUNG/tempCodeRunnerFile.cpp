class Graph {
    int num_vertices;
    vector<vector<int>> adj_list;

public:
    Graph(int num_vertices) : num_vertices(num_vertices) {
        adj_list.resize(num_vertices);
    }

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
    }

    bool is_hamiltonian() {
        vector<int> permutation(num_vertices);
        for (int i = 0; i < num_vertices; i++) {
            permutation[i] = i;
        }

        do {
            if (is_hamiltonian_path(permutation)) {
                return true;
            }
        } while (next_permutation(permutation.begin(), permutation.end()));

        return false;
    }

    bool is_hamiltonian_path(const vector<int>& permutation) {
        for (int i = 0; i < num_vertices - 1; i++) {
            int u = permutation[i];
            int v = permutation[i + 1];

            // Check if there is a directed edge between u and v
            bool found = false;
            for (int neighbor : adj_list[u]) {
                if (neighbor == v) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Graph graph(4);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 0);

    if (graph.is_hamiltonian()) {
        cout << "The graph has a unique topological order." << endl;
    } else {
        cout << "The graph does not have a unique topological order." << endl;
    }

    return 0;
}