#include<stdio.h>
#include<stdlib.h>
struct activity
{
    int start;
    int finish;
    int act;
};
void main()
{
    struct activity sol[100];
    struct activity temp;
    struct activity arr[100];
    int i,j,n,k=1;
    printf("Enter a number:");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        printf("Start time:");
        scanf("%d",&arr[i].start);
        printf("Finish time:");
        scanf("%d",&arr[i].finish);
        printf("Activity:");
        scanf("%d",&arr[i].act);
    }
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-i-2;j++)
        {
            if(arr[j].finish>arr[j+1].finish)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted table:\n");
    printf("Activity  start-time  finish-time\n");
    printf("-------------------------------------------------------------\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d %d %d\n",arr[i].act,arr[i].start,arr[i].finish);
    }
    sol[0]=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i].start>=sol[k-1].finish)
        {
            sol[k]=arr[i];
            k++;
        }
    }
    printf("Solution array:\n");
    for(i=0;i<=k-1;i++)
    {
        printf("A%d ",sol[i].act);
    }
}
