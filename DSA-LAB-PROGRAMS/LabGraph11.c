/*Design develop and implement a c program in c for the following operations on graph of cities
(a.) Create a graph of 'n' cities using adjacency matrix.
(b.) Print all reachable nodes from a given starting node in a diagraph using DFS or BFS method
*/ 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[20][20],vbfs[20],vdfs[20],n;

void bfs(int src)
{
    int i,j,q[20],f=0,r=-1;
    q[++r]=src;
    while(f<=r && r<n)
    {
        i=q[f++];
        printf("%d ",i);
        for(j=0;j<n;j++)
        {
            if(a[i][j]&&!vbfs[j])
            {
                vbfs[j]=1;
                q[++r]=j;
            }
        }
    }
}

void dfs(int src)
{
    int j;
    printf("%d ",src);
    vdfs[src]=1;
    for(j=0;j<n;j++)
    {
        if(a[src][j] && !vdfs[j])
        {
            dfs(j);
        }
    }
}

void main()
{
    int i,j,src,ch;
    printf("Enter numbers of nodes : ");
    scanf("%d",&n);
    printf("Enter Graph in matrix Form : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("1.BFS TRAVERSAL\n2.DFS TRAVERSAL\n3.EXIT\n");
    do{
        printf("Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: for(i=0;i<n;i++)
                        vbfs[i]=0;
                    printf("Enter the source Vertex : ");
                    scanf("%d",&src);
                    if(src<0 || src>=n)
                        printf("Invalid Vertex\n");
                    else
                    {
                        printf("Nodes Reachable from %d : \n",src);
                        bfs(src);
                        printf("\n");
                    }
                    break;
            case 2: for(i=0;i<n;i++)
                      vdfs[i]=0;
                    printf("Enter the source Vertex : ");
                    scanf("%d",&src);
                    if(src<0 || src>=n)
                        printf("Invalid Vertex\n");
                    else
                    {
                        printf("Nodes Reachable from %d : \n",src);
                        dfs(src);
                        printf("\n");
                    }
                    break;
            case 3: printf("<<<<<<<<<<< Terminating Program >>>>>>>>>>\n");
                    exit(0);
                    break;
            default: printf("Invalid Choice\n");                   

        }
    }
    while(ch!=3);
    _getch();
}
