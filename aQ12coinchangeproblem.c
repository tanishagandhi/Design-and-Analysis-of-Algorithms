#include <stdio.h>
#define MAX_COINS 100
#define MAX_VALUE 10000

int main()
{
    int n, coins[MAX_COINS], m[MAX_VALUE], s[MAX_VALUE],v;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    for (int i = 0; i <=n-1; i++)
    {
        printf("Enter the denominations of coins: ");
        scanf("%d", &coins[i]);
    }
    printf("Enter the value to make change for: ");
    scanf("%d", &v);
    m[0] = 0;
    for (int i = 1; i <= v; i++)
    {
        m[i] = MAX_VALUE;
        for (int j = 0;j<=n-1;j++) {
            if (coins[j] <= i && m[i-coins[j]]+1 < m[i])
            {
                m[i] = m[i-coins[j]]+1;
                s[i] = j;
            }
        }
    }
    printf("Minimum number of coins needed: %d\n", m[v]);
    printf("The selected coins are: ");
    while (v > 0) {
        printf("%d ", coins[s[v]]);
        v -= coins[s[v]];
    }
    printf("\n");
    return 0;
}


