/*#include <bits/stdc++.h>
using namespace std;

const int MAX_COINS = 1000; // Adjust this according to your needs
int main(){


  int amount;
  cin>>amount;
   int n;
   cin>>n;
   int coins[n];

    for (int i = 0; i <= n; i++) {
        cin>>coins[i];
    }

    int solution[n + 1][amount + 1];
    int dpTable[n + 1][amount + 1];



    for (int i = 0; i <= n; i++) {
        solution[i][0] = 0; // No coins needed to make change for 0
    }

    for (int j = 0; j <= amount; j++) {
        solution[0][j] = 0; // No coins needed to make change for 0
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i] <=j) {
                //solution[i][j] = solution[i - 1][j];
               int  inc_coin=1+ solution[i][j - coins[i]];
               int  exc_coin=solution[i - 1][j];
                solution[i][j]=min(inc_coin,exc_coin);


                   dpTable[i][j]= (inc_coin > exc_coin) ? (j - coins[i]) : j;
            }



             else {
                solution[i][j] =solution[i - 1][j]; ;
            }
        }
    }
    cout << "coins: " << solution[n][amount] << endl;
    int t = amount;

    for (int i = n; i > 0; i--) {
        if (dpTable[i][t] < t) {
            cout << " Value: " << coins[i] << endl;
            t = dpTable[i][t];
        }
    }

    return 0;



    }*/

    #include <bits/stdc++.h>
using namespace std;

const int MAX_COINS = 1000; // Adjust this according to your needs

int main() {
    int amount;
    cin >> amount;
    int n;
    cin >> n;
    int coins[n];

    for (int i = 0; i < n; i++) {  // Corrected loop condition
        cin >> coins[i];
    }

    int solution[n + 1][amount + 1];
    int dpTable[n + 1][amount + 1];

    for (int i = 0; i <= n; i++) {
        solution[i][0] = 0;
        dpTable[i][0] = 0;  // Initialize dpTable as well
    }



    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= amount; j++) {
            if (coins[i ] <= j) {  // Correct indexing for coins
                int inc_coin = 1 + solution[i][j - coins[i]];
                int exc_coin = solution[i - 1][j];
                solution[i][j] = min(inc_coin, exc_coin);
                dpTable[i][j] = (inc_coin > exc_coin) ? (j - coins[i]) : j;
            } else {
                solution[i][j] = solution[i - 1][j];
               // dpTable[i][j] = j;  // If coin cannot be included
            }
        }
    }

    cout << "Minimum coins needed: " << solution[n][amount] << endl;
    int t = amount;

    for (int i = n; i > 0; i--) {
        if (dpTable[i][t] < t) {
            cout << "Value: " << coins[i ] << endl;  // Correct indexing for coins
            t = dpTable[i][t];
        }
    }

    return 0;
}












