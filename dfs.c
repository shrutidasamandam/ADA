// LAB 4B - Check whether a given graph is connected or not using DFS method.

#include <stdio.h>
#include <stdlib.h>

int visited[10]={0},a[10][10],n;

void dfs(int v)
{
    int i;
    visited[v]=1;
    for(i=1;i<=n;i++)
    if(a[v][i] && !visited[i])
    {
        printf("\n%d-->%d\n",v,i);
        dfs(i);
    }
}

void main()
{
    int i,j,count=0;
    printf("\nEnter number of vertices");
    scanf("%d",&n);
    printf("\NEnter the adjacent matrix");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    dfs(1);
    for(i=1;i<=n;i++)
    {
        if(visited[i])
        count++;
    }
    if(n==count)
    printf("\ngraph is connected");
    else
    printf("\ngraph is not connected");
}
