#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void primMST(int startVertex) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       vector<bool> visited(V, false);//new

        vector<pair<int, int>> mstEdges; // To store the MST edges and their costs
        int mstCost = 0; // To store the total cost of the MST  //new

        pq.push({0, startVertex});

        while (!pq.empty()) {
            int u = pq.top().second;
            int weight = pq.top().first;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            mstCost += weight;

            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                if (!visited[v]) {
                    pq.push({w, v});
                    mstEdges.push_back({u, v}); // Store the edge and its cost
                }
            }
        }

        cout << "Minimum Spanning Tree Edges and Costs:\n";
        for (auto edge : mstEdges) {
            int u = edge.first;
            int v = edge.second;
            int cost = adj[u][v].second; // Cost of the edge between u and v
            cout << "Edge: " << u << " - " << v << ", Cost: " << cost << "\n";
        }

        cout << "Total MST Cost: " << mstCost << "\n";
    }
};

int main() {
    int V = 3;
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, 3);
    g.addEdge(0, 2, 1);

    // Finding minimum spanning tree using Prim's algorithm
    g.primMST(0);

    return 0;
}
