#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;

    double unit_price()
    {
        return (double)value / weight;
    }
};

class KnapsackComparator
{
public:
    bool operator()(Item a, Item b)
    {
        return a.unit_price() < b.unit_price();
    }
};

int main()
{
    int n, w;
    vector<Item> items;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int weight, value;
        cin >> weight >> value;

        Item item;
        item.weight = weight;
        item.value = value;
        items.push_back(item);
    }
    cin >> w;

    priority_queue<Item, vector<Item>, KnapsackComparator> pq;
    for(int i = 0; i < n; i++)
    {
        pq.push(items[i]);
    }

    double profit = 0.0;

    while(w > 0 && !pq.empty())
    {
        Item current = pq.top();
        pq.pop();

        if(w > current.weight)
        {
            cout << "Value: " << current.value << ", Weight: " << current.weight << endl;
            profit += current.value;
            w -= current.weight;
        }
        else
        {
            cout << "Value: " << current.value << ", Weight: " << w << endl;
            profit += current.unit_price() * w;
            w = 0;
        }
    }
    cout << "Profit: " << profit << endl;

    return 0;
}
