#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void print_lcs(char X[], char Y[], int m, int n, int L[][n+1])
{
    int index = L[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    printf("LCS is %s\n", lcs);
}

int lcs_length(char X[], char Y[], int m, int n) {
    int L[m+1][n+1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    print_lcs(X, Y, m, n, L);
    return L[m][n];
}

int main() {
    char X[100], Y[100],max;
    printf("Enter the first sequence: ");
    scanf("%s", X);
    printf("Enter the second sequence: ");
    scanf("%s", Y);
    int m = strlen(X);
    int n = strlen(Y);
    printf("Length of LCS is %d\n", lcs_length(X, Y, m, n));
    return 0;
}
