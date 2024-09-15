
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;  // n = number of items
    int k;  // k = knapsack weight
    cin >> n;
    int w[n + 1], v[n + 1];

    for (int i = 1; i <= n; i++) {  // Start loop from 1
        cin >> w[i] >> v[i];
    }

    cin >> k;
    int p[n + 1][k + 1];
    int dpTable[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        p[i][0] = 0;
        dpTable[i][0] = 0;
    }

    for (int j = 0; j <= k; j++) {
        p[0][j] = 0;
        dpTable[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (w[i] <= j) {
                int includeCurrentItem = p[i - 1][j - w[i]] + v[i];
                int excludeCurrentItem = p[i - 1][j];

                p[i][j] = max(includeCurrentItem, excludeCurrentItem);
                dpTable[i][j] = (includeCurrentItem > excludeCurrentItem) ? (j - w[i]) : j;
            } else {
                p[i][j] = p[i - 1][j];
               // dpTable[i][j] = j;
            }
        }
    }

    cout << "Profit: " << p[n][k] << endl;
    int t = k;

    for (int i = n; i > 0; i--) {
        if (dpTable[i][t] < t) {
            cout << "Weight: " << w[i] << ", Value: " << v[i] << endl;
            t = dpTable[i][t];
        }
    }

    return 0;
}

