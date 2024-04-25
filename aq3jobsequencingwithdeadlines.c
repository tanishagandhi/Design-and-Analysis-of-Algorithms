#include<stdio.h>
#include<stdlib.h>
struct job
{
    int profit;
    int deadline;
    int no;
};
void jobsequencing(struct job jobs[], int n)
{
    int i,j,max_deadline=0,max_profit=0;
    int slot[100] = {0};
    struct job sol[100];
    for(i=0;i<=n-1;i++)
    {
        if(jobs[i].deadline>max_deadline)
        {
            max_deadline=jobs[i].deadline;
        }
    }
    for (i = 0; i <=n-1; i++)
    {
        for (j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == 0)
            {
                slot[j] = 1;
                max_profit += jobs[i].profit;
                sol[j] = jobs[i];
                break;
            }
        }
    }
    printf("The maximum profit is %d.\n", max_profit);
    printf("The job sequence is: ");
    for(i=0; i<max_deadline; i++)
    {
        if(slot[i] != -1)
        {
            printf("J%d ", sol[i].no);
        }
    }
}

int main()
{
      int i,j,k,n;
      struct job jobs[100];
      struct job temp;
      printf("Enter no of jobs:");
      scanf("%d",&n);
      for(i=0;i<=n-1;i++)
      {
          printf("Enter profit:");
          scanf("%d",&jobs[i].profit);
          printf("Enter deadline:");
          scanf("%d",&jobs[i].deadline);
          printf("Job:");
          scanf("%d",&jobs[i].no);
      }
      for(i=0;i<=n-1;i++)
      {
          for(j=0;j<=n-i-2;j++)
          {
              if(jobs[j].profit<jobs[j+1].profit)
              {
                  temp=jobs[j];
                  jobs[j]=jobs[j+1];
                  jobs[j+1]=temp;
              }
          }
      }
      printf("After sorting:\n");
      printf("Jobs Deadline Profit\n");
      printf("------------------------------------------------\n");
      for(i=0;i<=n-1;i++)
      {
             printf("%d %d %d\n",jobs[i].no,jobs[i].deadline,jobs[i].profit);
      }
      jobsequencing(jobs,n);
      return 0;
}
