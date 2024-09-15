#include<bits/stdc++.h>
#define INF 99999
#define NIL -1
using namespace std;
 int dis[100];
 int parent[100];


 bool bellman(vector<pair<int,int>>all_edge,vector<double>weight,int n,int src){
     for(int i=1;i<=n;i++){
        dis[i]=INF;           //src theke all node & parent ke NIL and INF set korbo
        parent[i]=NIL;

     }

     for(int t=1;t<=n-1;t++){
        for(int ind=0;ind<all_edge.size();ind++){
            pair<int,int>cur_edge=all_edge[ind];//ekta kore edge ber korbo
            int l_node=cur_edge.first;
            int r_node=cur_edge.second;


            // Performing relax
            if(dis[r_node]>dis[l_node]+weight[ind]){
                    dis[r_node]=dis[l_node]+weight[ind];
                     parent[r_node]=l_node;

            }


        }
     }


     // Negative cycle check for each edge not v-1 times

     for(int ind=0;ind<all_edge.size();ind++){

         pair<int,int>cur_edge=all_edge[ind];//ekta kore edge ber korbo all_edge theke
            int l_node=cur_edge.first;
            int r_node=cur_edge.second;

         if(dis[r_node]>dis[l_node]+weight[ind]){
                 return false;

            }



     }

        return true;



 }

void print_path(int src,int des){
     if(src==des){
        cout<<src;

     }
     else{
        print_path(src,parent[des]);
        cout<<"-->"<<des;
     }



 }

 int main(){
     int n,e,src;
     cin>>n>>e>>src;
     vector<pair<int,int>>all_edge;//1D array
     vector<double>weight;

     for(int i=1;i<=e;i++){
         int l_node;
         int r_node;
         double wght;
         cin>>l_node>>r_node>>wght;
         pair<int,int>p(l_node,r_node);
         all_edge.push_back(p);
         weight.push_back(wght);


     }


     bellman(all_edge,weight,n,src);

    print_path(src,n);






 }
