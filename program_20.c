//Name - Yashika Rathore Roll no.- CT-A-26
#include <stdio.h>
#define MAX 20
int main() {
    int graph[MAX][MAX], indegree[MAX], queue[MAX];
    int n, i, j, front = 0, rear = -1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (DAG):\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }
    for(i = 0; i < n; i++) 
    {
        indegree[i] = 0;
        for(j = 0; j < n; j++)
            if(graph[j][i] == 1)
                indegree[i]++;
    }
    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            queue[++rear] = i;
    }
    printf("\nTopological Order: ");
    while(front <= rear) 
    {
        int node = queue[front++];
        printf("%d ", node);
        for(i = 0; i < n; i++) 
        {
            if(graph[node][i] == 1) 
            {
                indegree[i]--;
                if(indegree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }
    printf("\n");
    return 0;
}
