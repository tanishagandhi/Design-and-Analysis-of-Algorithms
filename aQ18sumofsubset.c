#include <stdio.h>

void subsetSum(int set[], int n, int sum, int currentSum, int selected[], int size)
{
    if (currentSum == sum)
    {
        printf("Subset with the given sum found:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", selected[i]);
        }
        printf("\n");
        return;
    }

    if (n == 0 || currentSum > sum)
        return;

    // Include the current element in the subset
    selected[size] = set[n - 1];
    subsetSum(set, n - 1, sum, currentSum + set[n - 1], selected, size + 1);

    // Exclude the current element from the subset
    subsetSum(set, n - 1, sum, currentSum, selected, size);
}

int main()
{
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    int sum;
    printf("Enter the target sum: ");
    scanf("%d", &sum);

    int selected[n];

    printf("\nOriginal Set:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", set[i]);
    printf("\n\n");

    subsetSum(set, n, sum, 0, selected, 0);

    return 0;
}
