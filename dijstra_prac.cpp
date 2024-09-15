#include<bits/stdc++.h>
using namespace std;
#define INF 99999

class Graph{
    int v;
    vector<vector<pair<int,int>>>adj;

    public:
        Graph(int v){
        this->v=v;


    }

    void addedge(int u,int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});



    }

    void dijstra(int src){

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

         vector dist(v,INF);
         pq.push({0,src});
         dist[src]=0;

         while(pq!=empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto neighbour:adj[u]){
                    int v=neighbour.first;
                     int w=neighbour.second;
                     if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight; // Update the distance if a shorter path is found
                    pq.push({dist[v], v});     // Push the updated distance and vertex to the priority queue
                }



            }



         }


    }




};

int main(){
    int v;
    Graph g(v);
    g.addedge(0,1,2);
    dijstra(0);





}
