//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#define MAX 10
int main()
{
    int adj[MAX][MAX], visited[MAX], stack[MAX], queue[MAX];
    int n, start, i, j;
    int top = -1, front = 0, rear = -1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        visited[i] = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(j >= i)
            {
                printf("Is edge exists between %d-%d? ", i, j);
                scanf("%d", &adj[i][j]);
                adj[j][i] = adj[i][j];
            }
        }
    }
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
    printf("\nEnter starting node for BFS: ");
    scanf("%d", &start);
    for(i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nBFS Traversal: ");
    visited[start] = 1;
    queue[++rear] = start;
    while(front <= rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        for(i = 0; i < n; i++)
        {
            if(adj[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n\nEnter starting node for DFS: ");
    scanf("%d", &start);
    for(i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nDFS Traversal: ");
    top = -1;
    stack[++top] = start;
    visited[start] = 1;
    printf("%d ", start);
    while(top != -1)
    {
        int node = stack[top];
        int found = 0;
        for(i = 0; i < n; i++)
        {
            if(adj[node][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
                printf("%d ", i);
                found = 1;
                break;
            }
        }
        if(!found)
            top--;
    }
    printf("\n");
    return 0;
}

