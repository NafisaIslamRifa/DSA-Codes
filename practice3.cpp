

#include<bits/stdc++.h>
using namespace std;

struct Item {
    string label;
    int weight;
    int value;

    double unit_price() {
        return (double)value / weight;
    }
};



    bool knapcom(Item a,  Item b) {
        return a.unit_price() > b.unit_price();
    }


int main() {
    int n;
    cin >> n;
    vector<Item> items;
    for (int i = 0; i < n; i++) {
        string label;
        int weight, value;
        cin >> label >> weight >> value;
        Item item;
        item.label = label;
        item.weight = weight;
        item.value = value;
        items.push_back(item);
    }

    int k;
    cin >> k;
    int knapsack_weight[k];
    for (int i = 0; i < k; i++) {
        cin >> knapsack_weight[i];
    }

    sort(items.begin(), items.end(), knapcom);


    struct Thief {
    int index;  // Thief index
    int capacity; // Thief's knapsack capacity
};


bool compareThieves( Thief a,  Thief b) {
    return a.index < b.index;  // Sort based on index (arrival order)
}


 vector<Thief> thieves;  // Vector of thieves


  for (int i = 0; i < k; i++) {
        Thief thief;
        thief.index = i;
        thief.capacity = knapsack_weight[i];
        thieves.push_back(thief);
    }

    sort(thieves.begin(), thieves.end(), compareThieves);




    double profit = 0.00;
    int total_thieves = 0;
   for (int i = 0; i < thieves.size(); i++) {
    double thief_profit = 0.00;
    for (int j = 0; j < items.size(); j++) {
    if (items[j].weight <= thieves[i].capacity) {
        thieves[i].capacity -= items[j].weight;
        thief_profit += items[j].value;
    }
}

    profit += thief_profit;
    if (thief_profit > 0.00) {
        total_thieves++;
    }
}

}


