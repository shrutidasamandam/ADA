// lab 4B
#include <stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f=0, r=-1;
void bfs(int v);
void main()
{
  int v;
  printf("\nEnter number of vertices: ");
  scanf("%d",&n);
  printf("\nEnter adjacency matrix: ");
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  printf("\nEnter value of starting vertex");
  scanf("%d",&v);
  for(i=0; i<n; i++)
  {
    q[i] = 0;
    visited[i] = 0;
  }
  bfs(v);
  printf("\n The reachable nodes are ");
  for(i=0; i<n; i++)
  {
    if(visited[i])
    printf("%d\t",i);
  }
}

void bfs(int v)
{
  for(i=0; i<n; i++)
  {
    if(a[v][i] && !visited[i])
    q[++r] = i;
  }
  if(f<=r)
  {
    visited[q[f]] = 1;
    bfs(q[++f]);
  }
}
