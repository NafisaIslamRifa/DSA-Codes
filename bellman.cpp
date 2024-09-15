

#include <bits/stdc++.h>
using namespace std;

#define INF 99999
#define NIL -1

double dis[100];
int parent[100];

bool Bellman(vector<pair<int, int>> all_edge, vector<double> weight, int n, int src) {
    // dis[src] = 0;

    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
        parent[i] = NIL;
    }

     dis[src] = 0;




    // Relaxing
    for (int t = 1; t <= n - 1; t++) {
        for (int ind = 0; ind < all_edge.size(); ind++) {
            pair<int, int> cur_edge = all_edge[ind];
            int l_node = cur_edge.first;
            int r_node = cur_edge.second;

            // Performing relax
            if (dis[r_node] > dis[l_node] + weight[ind]) {
                dis[r_node] = dis[l_node] + weight[ind];
                parent[r_node] = l_node;
            }
        }
    }

    // Negative cycle check
    for (int ind = 0; ind < all_edge.size(); ind++) {
        pair<int, int> cur_edge = all_edge[ind];
        int l_node = cur_edge.first;
        int r_node = cur_edge.second;

        // Performing relax
        if (dis[r_node] > dis[l_node] + weight[ind]) {
            return false;
        }
    }

    return true;
}

void print_path(int src, int dst) {
    if (src == dst) {
        cout << src;
    }
     else {
        print_path(src, parent[dst]);
        cout << " -> " << dst;
    }
}

int main() {
    int n, e, src;
    cin >> n >> e >> src;

    vector<pair<int, int>> all_edge;
    vector<double> weight;
    for (int i = 1; i <= e; i++) {
        int l_node, r_node;
        double wght;
        cin >> l_node >> r_node >> wght;
        pair<int, int> p(l_node, r_node);

        all_edge.push_back(p);
        weight.push_back(wght);
    }

    Bellman(all_edge,weight,n,src);

    print_path(src,n);

    return 0;
}


















