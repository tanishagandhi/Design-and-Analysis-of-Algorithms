\#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 10

int tsp(int graph[MAX_SIZE][MAX_SIZE], int n, int start, int visited)
{
    if (visited == (1 << n) - 1)
        return graph[start][0];

    int min_cost = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (!(visited & (1 << i)))
        {
            int cost = graph[start][i] + tsp(graph, n, i, visited | (1 << i));
            if (cost < min_cost)
                min_cost = cost;
        }
    }

    return min_cost;
}

int main()
{
    int n, i, j;
    int graph[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int start = 0; // Starting city (Assuming it to be 0th city)

    int visited = 1 << start;

    int min_cost = tsp(graph, n, start, visited);

    printf("Minimum cost of the TSP tour: %d\n", min_cost);

    return 0;
}
