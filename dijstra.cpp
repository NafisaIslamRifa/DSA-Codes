#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class Graph {
    int V;                          // Number of vertices in the graph
    vector<vector<pair<int, int>>> adj; // Adjacency list to store edges
     //list:(vertex,distance/weight)

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);            // Resize the adjacency list to accommodate V vertices
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w}); // Add an edge from u to v with weight w
        adj[v].push_back({u, w}); // Also add the reverse edge from v to u with the same weight
    }

    void shortestPath(int src){
                           //(pair<int, int>)storing pair in pq,  (distance,vertex)
                           //vector<pair<int, int>> using this vector that holds the elements


     //greater<pair<int, int>>:
     //  comparator function to sorted in the priority queue.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;



        vector<int> dist(V, INF);  // Initialize distances to all vertices as infinity
        //dist er size v

        pq.push({0, src});         // Push the source vertex with distance 0
        dist[src] = 0;             // Set the distance of source vertex to 0

        while (!pq.empty()) {
            int u = pq.top().second; // Get the vertex with the smallest known distance
            pq.pop();

            for (auto neighbor : adj[u]) {
                int v = neighbor.first;     // Neighbor vertex
                int weight = neighbor.second; // Weight of the edge to the neighbor

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight; // Update the distance if a shorter path is found
                    pq.push({dist[v], v});     // Push the updated distance and vertex to the priority queue
                }
            }
        }

        // Printing the results
        cout << "Vertex Distance from Source\n";
        for (int i = 0; i < V; ++i) {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }
};

int main() {
    int V = 9;
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1, 4);
     g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    // Finding shortest paths from source vertex
    g.shortestPath(0);

    return 0;
}


/*
Vertex 0: (1, 4) (7, 8)
Vertex 1: (0, 4) (2, 8) (7, 11)
Vertex 2: (1, 8) (3, 7) (8, 2) (5, 4)
Vertex 3: (2, 7) (4, 9) (5, 14)
Vertex 4: (3, 9) (5, 10)
Vertex 5: (2, 4) (3, 14) (4, 10) (6, 2)
Vertex 6: (5, 2) (7, 1) (8, 6)
Vertex 7: (0, 8) (1, 11) (6, 1) (8, 7)
Vertex 8: (2, 2) (6, 6) (7, 7)


/*

/*
The algorithm's main loop iterates as long as there are vertices in the priority queue,
 which happens until all vertices have been processed and their shortest distances have
 been updated. In each iteration, the vertex with the smallest known distance is popped
  from the priority queue. Then, for each neighbor of that vertex, the algorithm checks
  whether updating the distance to that neighbor would lead to a shorter path. If it does,
   the distance is updated and the neighbor is pushed back into the priority queue with
    its updated distance.
*/
