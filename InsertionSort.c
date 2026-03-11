#include <stdio.h>
#include <stdlib.h>
int count;
void insertionsort(int a[10],int s,int r)
{
    int i,item,j;
    for(i=1;i<=r;i++)
    {
        item=a[i];
        j=i-1;
        while(j>=0 && item<a[j])
        {
            count++;
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=item;
    }
}
int main()
{
    int i,n,a[10];
    printf("\nEnter Array Size:");
    scanf("%d",&n);
    printf("\nEnter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertionsort(a,0,n-1);
    printf("\nSorted Elements are:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\nTotal number of comparisions:%d",count);
    return 0;
}
