


#include<stdio.h>
#include<limits.h>

int maxSubArraySum_new(int arr[], int n) {
    int maxsum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i; j <= n; j++) {
            int tempsum = 0;

            for (int k = i; k < j; k++) {
                tempsum += arr[k];
            }

            if (tempsum > maxsum) {
                maxsum = tempsum;
            }
        }
    }

    return maxsum;
}

int main() {
    int n = 4;

    int a[] = {2, 1, -3, 9};

    int d = maxSubArraySum_new(a, n);
    printf("%d", d);

    return 0;
}

