#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void create_graph(int a[MAX][MAX],int vertices,int edges)
{
    int i,j;
    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            a[i][j] = 0;
        }
    }
    int u,v;
    for(i=0;i<edges;i++)
    {
        printf("enter source : ");
        scanf("%d",&u);
        printf("enter target : ");
        scanf("%d",&v);
        a[u][v] = a[v][u] = 1;
    }
}
void display(int a[MAX][MAX],int vertices,int edges)
{
    int i,j;
    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void dfs(int source,int a[MAX][MAX],int visited[MAX],int vertices)
{
    printf("%d ",source);
    visited[source] = 1;
    int i;
    for(i=0;i<vertices;i++)
    {
        if(a[source][i]==1 && visited[i]==0)
        {
            dfs(i,a,visited,vertices);
        }
    }

}

int main()
{
    int vertices;
    printf("enter number of vertices : ");
    scanf("%d",&vertices);
    int edges;
    printf("enter number of edges : ");
    scanf("%d",&edges);
    int a[MAX][MAX];
    create_graph(a,vertices,edges);
    display(a,vertices,edges);
    
    int visited[MAX];
    int i;
    for(i=0;i<vertices;i++)
    {
        visited[i] = 0;
    }

    int source;
    printf("enter source from 0 to %d : ",(vertices-1));
    scanf("%d",&source);
    printf("dfs traversal : ");
    dfs(source,a,visited,vertices);
}
/*
int main()
{
    int a[MAX][MAX];
    int edge,vertices;
    printf("enter number of vertices : ");
    scanf("%d",&vertices);
    printf("enter number of edges : ");
    scanf("%d",&edge);
    create_graph(a,vertices,edge);
    display(a,vertices,edge);
    int visited[vertices];
    int i;
    for(i=0;i<vertices;i++)
    {
        visited[i] = 0;
    }
    int s;
    printf("Enter source node for dfs traversal (0 to %d) : ",vertices-1);
    scanf("%d",&s);
    dfs(s,a,visited,vertices);
}*/