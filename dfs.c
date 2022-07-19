// LAB 4A

#include <stdio.h>
#include <conio.h>

int a[10][10], n, vis[10]

int dfs(int);

void main()
{
    int i,j,src,ans;
    for(j=1; j<=n; j++)
    {
        vis[j] = 0;
    }
    printf("\nEnter no. of nodes:\n");
    scanf("%d",&n);
    printf("\nEnter adjacency matrix
    for(i=1; i<=n;i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter source node");
    scanf("%d",&src);
    ans = dfs(src);
    if(ans == 1)
    {
        printf("\nGraph is connected");
    } else {
        printf("\nGraph is not connected")
    }
}

int dfs (int src) {
    int j;
    vis[src] = 1;
    for(j=1; j<=n; j++)
    {
        if(a[src][j]==1&&vis[j]!=1)
        {
            dfs(j);
        }
    }
    for(j=1; j<=n; j++)
    {
        if(vis[j]!=1)
        {
            printf ("\n node %d is not reachable\n", j);
        } else {
            printf (" \n node %d is reachable \n", j);
        }
    }
}
