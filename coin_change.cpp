/*#include<iostream>
#include<algorithm>

using namespace std;


int min_coin(int coins[], int n, int amount) {
    int no_coins = 0;

    sort(coins,coins+n,greater<int>());

    for (int i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            int need = amount / coins[i];
            amount -= coins[i] * need;
            no_coins += need;
        }
    }

    return no_coins;
}

int main()

{
   int n;
   int amount;
cout<<"enter no of coin"<<endl;
   cin>>n;
   cout<<"enter amount"<<endl;
   cin>>amount;
   cout<<"enter coins"<<endl;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];

}

//sort(a,a+n);
int d=min_coin(a,n,amount);
cout<<d;
}*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> min_coins_used;//vector global

int min_coin(int coins[], int n, int amount) {//function er moddhe sort ,sort korar por condition
    int no_coins = 0;

    sort(coins, coins + n, greater<int>());


    for (int i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            int need = amount / coins[i];
            amount -= coins[i] * need;
            no_coins += need;
            while (need--)
                min_coins_used.push_back(coins[i]);
        }
    }

    return no_coins;
}

int main() {
    //int n = 4; // Number of denominations (25 cents, 10 cents, 5 cents, 1 cent)
    int n,amount;
    cout<<"enter no of coin"<<endl;
    cin>>n;
   cout<<"enter amount"<<endl;
   cin>>amount;
   cout<<"enter coins"<<endl;
   int coins[n];
   for(int i=0;i<n;i++){
    cin>>coins[i];
   }

    //int amount = 173; // The amount we want to make

    //int coins[] = {25, 10, 5, 1}; // Available denominations

    int minCoins = min_coin(coins, n, amount);
    cout << "Minimum number of coins needed: " << minCoins << endl;

    if (minCoins > 0) {
        cout << "Coins taken: ";
        for (int i = 0; i < min_coins_used.size(); i++) {
            cout << min_coins_used[i]<<"  cents"<<endl;
            //if (i < min_coins_used.size() - 1)
                //cout << ", ";
        }
        cout << endl;
    }

    return 0;
}
