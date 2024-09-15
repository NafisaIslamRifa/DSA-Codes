



#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main()
{
    int numItems, totalWeight;

    // Input the number of items (n)
    scanf("%d", &numItems);
    int weight[numItems + 1], value[numItems + 1];

    // Input weights and values of each item
    for (int i = 1; i <= numItems; i++)
    {
        scanf("%d%d", &weight[i], &value[i]);
    }

    // Input the maximum total weight capacity (W)
    scanf("%d", &totalWeight);

    // Create arrays to store the maximum profit (P) and the previous item index (T)
    int maxProfit[numItems + 1][totalWeight + 1];
    int prevItem[numItems + 1][totalWeight + 1];

    // Initialize the base cases: When there are no items (i=0) or total weight is 0 (j=0)
    for (int i = 0; i <= numItems; i++)
    {
        maxProfit[i][0] = 0;
        prevItem[i][0] = 0;
    }
    for (int j = 0; j <= totalWeight; j++)
    {
        maxProfit[0][j] = 0;
        prevItem[0][j] = 0;
    }

    // Dynamic programming loop to compute maximum profit for each item and weight
    for (int i = 1; i <= numItems; i++)
    {
        for (int j = 1; j <= totalWeight; j++)
        {
            if (weight[i] <= j)
            {
                int includeCurrentItem = maxProfit[i - 1][j - weight[i]] + value[i];
                int excludeCurrentItem = maxProfit[i - 1][j];

                maxProfit[i][j] = max(includeCurrentItem, excludeCurrentItem);
                prevItem[i][j] = (includeCurrentItem > excludeCurrentItem) ? (j - weight[i]) : j;
            }
            else
            {
                // Cannot include the current item, so inherit the profit from the previous item
                maxProfit[i][j] = maxProfit[i - 1][j];
            }
        }
    }

    // Print the maximum profit achieved
    printf("Max profit = %d\n", maxProfit[numItems][totalWeight]);

    int remainingWeight = totalWeight;
    // Backtrack to find the items included in the optimal solution
    for (int i = numItems; i > 0; i--)
    {
        if (prevItem[i][remainingWeight] < remainingWeight)
        {
            printf("Weight = %d, Value = %d\n", weight[i], value[i]);
            remainingWeight = prevItem[i][remainingWeight];
        }
    }
    return 0;
}



