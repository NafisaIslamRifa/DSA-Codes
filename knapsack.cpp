
#include <iostream>
#include <vector>
#include <algorithm>
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

bool knapsackComparator(Item a, Item b)
{
    return a.unit_price() > b.unit_price(); // Note the change in the comparison here
}                                            //sort in desceding order of unit price

int main()
{
    int n, w;
    vector<Item> items;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int weight, value;
        cin >> weight >> value;

        Item item;
        item.weight = weight;
        item.value = value;
        items.push_back(item);
    }
    cin >> w;

    sort(items.begin(), items.end(), knapsackComparator);//sort will sort the entire
    // vector of items based on their unit prices,

    double profit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (w > items[i].weight)
        {
            cout << "Value: " << items[i].value << ", Weight: " << items[i].weight << endl;
            profit += items[i].value;
            w -= items[i].weight;
        }
        else
        {
            cout << "Value: " << items[i].value << ", Weight: " << w << endl;
            profit += items[i].unit_price() * w;
            w = 0;
            break; // If the knapsack capacity is fully used, exit the loop
        }
    }
    cout << "Profit: " << profit << endl;

    return 0;
}
