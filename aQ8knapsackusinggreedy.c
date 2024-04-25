#include<stdio.h>
#include<string.h>

struct process {
    int value;
    int weight;
    int no;
    float ratio;
};

int main() {
    int i, j, n, max, index = 0;
    float wt = 0, frac,totalval = 0;
    struct process process[100];
    struct process temp;
    struct process sol[100];
    memset(sol, 0, sizeof(sol));
    printf("Enter no of processes: ");
    scanf("%d", &n);
    printf("Enter max weight: ");
    scanf("%d", &max);
    for(i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &process[i].value);
        printf("Enter weight: ");
        scanf("%d", &process[i].weight);
        printf("Process: ");
        scanf("%d", &process[i].no);
        process[i].ratio = (float)process[i].value / (float)process[i].weight;
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(process[j].ratio < process[j + 1].ratio) {
              temp = process[j];
              process[j] = process[j + 1];
              process[j + 1] = temp;
            }
        }
    }
    printf("\nProcess  Value Weight Ratio\n");
    printf("-------------------------------------------------\n");
    for(i = 0; i < n; i++) {
        printf("%d        %d      %d     %f\n", process[i].no, process[i].value, process[i].weight, process[i].ratio);
    }
    for(i = 0; i < n; i++) {
        if(wt + process[i].weight<= max) {
            sol[index].weight = process[i].weight;
            sol[index].value = process[i].value;
            sol[index].no = process[i].no;
            index++;
            wt += process[i].weight;
            totalval += process[i].value;
        }
        else {
            frac = (float)(max - wt) / (float)(process[i].weight);
            sol[index].weight = frac * process[i].weight;
            sol[index].value = frac * process[i].value;
            sol[index].no = process[i].no;
            index++;
            totalval += process[i].value * frac;
            wt += process[i].weight * frac;
            break;
        }
    }
    printf("\nSolution is:\n");
    for(i = 0; i <=index-1; i++)
    {
        if(sol[i].weight != process[i].weight)
        {
            printf("I%d*%f\n",sol[i].no,frac);
        }
        else
        {
                printf("I%d\n",sol[i].no);
        }

    }
    printf("\nTotal weight: %f", wt);
    printf("\nTotal profit: %f\n", totalval);
    return 0;
}
