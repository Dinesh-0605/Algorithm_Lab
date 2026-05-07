#include <stdio.h>
#include <stdlib.h>
int n,d,W[10],X[10];
void Sum_of_Subset(int s,int k, int r)
{
    int i;
    static int count=1;
    X[k]=1;
    if(s+W[k]==d)
    {
        printf("\nSolution %d=\t",count++);
        for(i=1;i<=k;i++)
        {
            if(X[i]==1)
                printf("%d\t",W[i]);
        }
        printf("\n");
    }
    else if(s+W[k]+W[k+1]<=d)
        Sum_of_Subset(s+W[k],k+1,r-W[k]);
    if(s+r-W[k]>=d && s+W[k+1]<=d)
    {
        X[k]=0;
        Sum_of_Subset(s,k+1,r-W[k]);
    }
}
int main()
{
    int i,sum=0;
    printf("\nRead number of elements:");
    scanf("%d",&n);
    printf("\nRead elements in ascending order:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&W[i]);
        sum+=W[i];
    }
    printf("\nRead value of d:");
    scanf("%d",&d);
    Sum_of_Subset(0,1,sum);
    return 0;
}
