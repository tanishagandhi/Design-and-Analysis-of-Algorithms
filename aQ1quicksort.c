#include<stdio.h>
#include<conio.h>

int partition(int a[100], int l, int u) {
    int v = a[l], i = l, j = u + 1, temp;
    do {
        do {
            i++;
        } while (a[i] < v && i <= u);
        do {
            j--;
        } while (a[j] > v && j >= l);
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    a[l] = a[j];
    a[j] = v;
    return j;
}

void quicksort(int a[100], int l, int u) {
    int v;
    if (l < u) {
        v = partition(a, l, u);
        quicksort(a, l, v - 1);
        quicksort(a, v + 1, u);
    }
}

void main() {
    int a[100], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    getch();
}
