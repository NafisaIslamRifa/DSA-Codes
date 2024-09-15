#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int A[], int n, int N) {
    bool dp[n + 1][N + 1];

    // Base case: A sum of 0 can always be achieved by an empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= N; j++) {
            // If the current element is greater than the target sum
            // Exclude it and check the previous subset
            if (A[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Include the current element or exclude it
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
            }
        }
    }

    return dp[n][N];
}

int main() {
    int A[] = {2, 4, 5, 6, 8};
    int n = sizeof(A) / sizeof(A[0]);

    int N;

    // Input the target sum N
    cin >> N;

    if (isSubsetSum(A, n, N)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

