
#include <bits/stdc++.h>
using namespace std;

int p[100], rankArray[100];

int find_set(int x)
{
    if (x != p[x])
    {
        p[x] = find_set(p[x]);
    }
    return p[x];
}

void link(int x, int y)
{
    if (rankArray[x] > rankArray[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
        if (rankArray[x] == rankArray[y]) // Renamed 'rank' to 'rankArray'
        {
            rankArray[y]++;
        }
    }
}

void make_set(int x)
{
    p[x] = x;
    rankArray[x] = 0;
}

void union_set(int x, int y)
{
    link(find_set(x), find_set(y));
}

bool sortfn(const pair<int, pair<int, int>>& edge1, const pair<int, pair<int, int>>& edge2) {
    return edge1.first < edge2.first;
}

void krushkal(vector<pair<int,pair<int,int>>> all_edge){

    sort(all_edge.begin(), all_edge.end(), sortfn);

    int ans=0;

    for (int ind = 0; ind < all_edge.size(); ind++)
    {
        pair<int, pair<int, int>> var = all_edge[ind];
        int weight = var.first;
        int l_node = var.second.first;
        int r_node = var.second.second;

        if (find_set(l_node) != find_set(r_node))
        {
            union_set(l_node, r_node);
            ans+=weight;
            cout<<"edges of MST"<<endl;
            //cout<<l_node<<" "<<r_node<<" "<<weight<<endl;
            cout << "Edge of MST: " << l_node << " " << r_node << " Cost: " << weight << endl;
        }
    }

    cout<<"cost"<<ans;


}


int main()
{
    int v, e;

    cin >> v >> e;

    for (int node = 1; node <= v; node++)
    {
        make_set(node);
    }

    vector<pair<int,pair<int,int>>> all_edge;

    for (int i = 0; i < e; i++)
    {
        int l_node, r_node;
        int weight;
        cin >> weight >> l_node >> r_node;

        pair<int, pair<int, int>> p(weight, make_pair(l_node, r_node));
        all_edge.push_back(p);
    }

}


//If two vertices have the same parent (i.e.,
                                        // they are in the same set), then adding the edge between them would create a cycle.
