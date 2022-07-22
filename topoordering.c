// LAB 6 - Write program to obtain the Topological ordering of vertices in a given digraport technique and compute its time taken. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10][10],n,indegree[10];

void find_degree()
{
    int i,j,sum;
    for(j=0;j<n;j++)
    {
        sum = 0;
        for(i=0; i<n; i++)
            sum = sum + a[i][j];
        indegree[j] = sum;
    }
}

void topo()
{
    int i,u,v,t[10],s[10],top=-1,k=0;
    find_degree();
    for(i=0; i<n; i++)
    {
        if(indegree[i]==0) s[++top] = i;
    }
    while(top!=-1)
    {
        u = s[top--];
        t[k++] = u;
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1)
            {
                indegree[v]--;
                if(indegree[v]==0) s[++top] = v;
            }
        }
    }
    printf("\n topological ordering:\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",t[i]);
    }
}

void main()
{
    int i,j;
    clock_t c;
    printf("\nEnter number of nodes");
    scanf("%d",&n);
    printf("\nEnter adjacent matrix");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    c = clock();
    topo();
    c = c-clock();
    printf("\nTime taken to order the vertices: %lu",c/CLOCKS_PER_SEC);
}
