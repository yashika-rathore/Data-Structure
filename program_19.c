//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], n;
int visited[MAX];
void DFS(int u, int ignore) 
{
    visited[u] = 1;
    for(int v = 0; v < n; v++) 
    {
        if(v == ignore) 
            continue;
        if(adj[u][v] && !visited[v])
            DFS(v, ignore);
    }
}
int isConnected(int ignore) 
{
    int start = -1;
    for(int i = 0; i < n; i++)
        if(i != ignore) 
        { 
            start = i; 
            break; 
        }
    for(int i = 0; i < n; i++) 
        visited[i] = 0;
    DFS(start, ignore);
    for(int i = 0; i < n; i++)
        if(i != ignore && !visited[i])
            return 0;
    return 1;
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    for(int i = 0; i < n; i++) 
    {
        if(!isConnected(i)) 
        {
            printf("Graph is NOT biconnected\n");
            return 0;
        }
    }
    printf("Graph IS biconnected\n");
    return 0;
}
