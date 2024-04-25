#include<stdio.h>
#include<conio.h>
void merge(int a[],int l,int m,int u)
{
    int i=l,j=m+1,k=0,b[100];
    while(i<=m && j<=u)
    {
	    if(a[i]<a[j])
	    {
	      b[k]=a[i];
	      k++;
	      i++;
	    }
	    else
	    {
		 b[k]=a[j];
		 k++;
		 j++;
	    }
    }
    while(i<=m)
    {
	 b[k]=a[i];
	 k++;
	 i++;
    }
    while(j<=u)
    {
	b[k]=a[j];
	k++;
	j++;
    }
    for(i=l,k=0;i<=u;i++,k++)
    {
	 a[i]=b[k];
    }
}
void mergesort(int a[],int l,int u)
{
       int m;
       if(l<u)
       {
	    m=(l+u)/2;
	    mergesort(a,l,m);
	    mergesort(a,m+1,u);
	    merge(a,l,m,u);
       }
}
void main()
{
     int i,n,a[100];
     printf("Enter no of elements:");
     scanf("%d",&n);
     for(i=0;i<=n-1;i++)
     {
	  printf("Enter the element:");
	  scanf("%d",&a[i]);
     }
     mergesort(a,0,n-1);
     printf("After sorting:\n");
     for(i=0;i<=n-1;i++)
     {
	   printf("%d\n",a[i]);
     }
     getch();
}

