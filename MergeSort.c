#include <stdio.h>
#include <stdlib.h>

int count;

void merge(int a[10],int l,int m,int r)
{
    int i,j,k,b[10];
    i=l;
    j=m+1;
    k=l;
    while(i<=m && j<=r)
    {
        count=count+1;
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m)
        b[k++]=a[i++];
    while(j<=r)
        b[k++]=a[j++];
    for(i=l;i<=r;i++)
        a[i]=b[i];
}

void mergesort(int a[10],int l,int r)
{
    int m;
    if(l<r)
    {
        m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main()
{
    int n,i,a[10];
    printf("\n Read Array Size: ");
    scanf("%d",&n);
    printf("\n Read Array Elements: \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("\n Sorted Elements Are:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n Total Number Of comparisions:%d",count);
    return 0;
}
