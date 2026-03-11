#include <stdio.h>
#include <stdlib.h>
int count;
int partition(int a[10],int l,int r)
{
    int pivot,i,j,temp;
    pivot=a[l];
    i=l+1;
    j=r;
    while(1)
    {
        while(pivot>=a[i]&&i<=r)
        {
            count++;
            i++;
        }
        while(pivot<a[j])
        {
            count++;
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else{
            temp=a[l];
            a[l]=a[j];
            a[j]=temp;
            return j;
        }
    }
}
void QuickSort(int a[10],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        QuickSort(a,l,s-1);
        QuickSort(a,s+1,r);
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
    QuickSort(a,0,n-1);
    printf("\nSorted Elements are:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\nTotal number of comparisions:%d",count);
    return 0;
}
