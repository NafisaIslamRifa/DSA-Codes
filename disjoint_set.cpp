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
        if (rankArray[x] == rankArray[y])
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

int main()
{
    int v, e;

    cin >> v >> e;
    vector<pair<int, int>> all_edge;

    for (int i = 0; i < e; i++)
    {
        int l_node, r_node;
        cin >> l_node >> r_node;
        pair<int,int>p(l_node,r_node);
        all_edge.push_back(p);
       // all_edge.push_back(make_pair(l_node, r_node));
    }

    for (int node = 1; node <= v; node++)
    {
        make_set(node);
    }

    for (int ind = 0; ind < all_edge.size(); ind++)
    {
        pair<int, int> each_edge = all_edge[ind];
        int l_node = each_edge.first;
        int r_node = each_edge.second;

        if (find_set(l_node) != find_set(r_node))
        {
            union_set(l_node, r_node);
        }
    }

    // Showing each node representative
    for (int i = 1; i <= v; i++)
    {
        cout << i << " rep " << find_set(i) << endl;
    }

    return 0;
}
