/*Design develop and implement a c program in c for the following operations on graph of cities
(a.) Create a graph of 'n' cities using adjacency matrix.
(b.) Print all reachable nodes from a given starting node in a diagraph using DFS or BFS method
*/ 

#include <stdio.h>
#include <stdlib.h>

int adj[20][20],source,visitedBFS[20],visitedDFS[20],n;

void ReadData()
{
    int i,j;
    printf("Enter no. of Vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    }
}

void PrintData(int visited[])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(visited[i])
            printf("%d is reachable\n",i);
    }
}

void BFS()
{
    int q[20],f=0,r=-1,i,j;
    q[++r]=source;
    while(f<=r)
    {
        i=q[f++];
        printf("%d ",i);
        for(j=0;j<n;j++)
        {
            if(adj[i][j] && !visitedBFS[j])
            {
                visitedBFS[j]=1;
                q[++r]=j;
            }
        }
    }
}

void DFS(int source)
{
    int j;
    printf("%d ",source);
    visitedDFS[source]=1;
    for(j=0;j<n;j++)
    {
        if(adj[source][j] && !visitedDFS[j])
        {
            DFS(j);
        }
    }
}

void main()
{
    int i,choice;
    ReadData();
    for(;;)
    {       
        printf("1.BFS Traversal\n2.DFS Traversal\n3.Exit\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
       {
          case 1: printf("Enter the Starting Vertex : ");
                  scanf("%d",&source);
                  for(i=0;i<n;i++)
                        visitedBFS[i]=0;
                  BFS();
                  printf("Nodes Reachable from %d are : \n",source);
                  PrintData(visitedBFS);
                  break;
            case 2: printf("Enter the Starting Vertex : ");
                    scanf("%d",&source);
                  for(i=0;i<n;i++)
                        visitedDFS[i]=0;
                  DFS(source);
                  printf("Nodes Reachable from %d are : \n",source);
                  PrintData(visitedDFS);
                  break;
            case 3: printf("<<<<<<<<<<<<< Terminating >>>>>>>>>>>>>>\n");
                    exit(0);
            default: printf("Invalid Choice entered\n");
       }
    }
}
/*
OUTPUT :
Enter no. of Vertices
4
Enter the adjacency matrix
0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0 
1.BFS Traversal
2.DFS Traversal
3.Exit
Enter Your Choice : 1
Enter the Starting Vertex : 2
2 3 Nodes Reachable from 2 are : 
3 is reachable
1.BFS Traversal
2.DFS Traversal
3.Exit
Enter Your Choice : 2
Enter the Starting Vertex : 2
2 3 Nodes Reachable from 2 are : 
2 is reachable
3 is reachable
1.BFS Traversal
2.DFS Traversal
3.Exit
Enter Your Choice : 3
<<<<<<<<<<<<< Terminating >>>>>>>>>>>>>>
*/
