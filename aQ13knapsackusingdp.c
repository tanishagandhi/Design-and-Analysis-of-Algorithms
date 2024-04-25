
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {

                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxValue = dp[n][W];
    printf("Maximum value that can be achieved: %d\n", maxValue);

    printf("Selected items: ");
    int w = W;
    for (int i = n; i > 0 && maxValue > 0; i--) {
        if (maxValue != dp[i - 1][w]) {
            printf("%d ", i);
            maxValue -= val[i - 1];
            w -= wt[i - 1];
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n];
    int wt[n];

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i + 1);
        printf("Value: ");
        scanf("%d", &val[i]);
        printf("Weight: ");
        scanf("%d", &wt[i]);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsack(capacity, wt, val, n);

    return 0;
}
