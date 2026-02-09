
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int dfn[MAX], low[MAX], parent[MAX];
int visited[MAX], articulation[MAX];
int time_counter = 0;  // Global timer for discovery and low values

void dfnlow(int u, int adj[MAX][MAX], int V)
{
    int children = 0;
    int v;
    
    visited[u] = 1;
    dfn[u] = low[u] = ++time_counter;
    
    for (v = 0; v < V; v++)
    {
        if (adj[u][v])  // If there is an edge from u to v
        {
            if (!visited[v])  // v is not visited (tree edge)
            {
                children++;
                parent[v] = u;
                dfnlow(v, adj, V);
                
                // Update low value of u with low value of child v
                if (low[u] > low[v])
                    low[u] = low[v];
                
                // Check for articulation point conditions
                // 1. Root node with at least two children
                if (parent[u] == -1 && children > 1)
                    articulation[u] = 1;
                
                // 2. Non-root node where no child has back edge to ancestor
                if (parent[u] != -1 && low[v] >= dfn[u])
                    articulation[u] = 1;
            }
            else if (v != parent[u])  // Back edge (not to immediate parent)
            {
                // Update low value using discovery time of ancestor
                if (low[u] > dfn[v])
                    low[u] = dfn[v];
            }
        }
    }
}

void findArticulationPoints(int adj[MAX][MAX], int V)
{
    int i;
    
    // Initialize all arrays
    for (i = 0; i < V; i++)
    {
        parent[i] = -1;
        visited[i] = 0;
        articulation[i] = 0;
        dfn[i] = low[i] = 0;
    }
    
    time_counter = 0;
    
    // Handle possibly disconnected graph
    for (i = 0; i < V; i++)
    {
        if (!visited[i])
            dfnlow(i, adj, V);
    }
    
    // Print results
    printf("\nArticulation points (Critical Routers) are:\n");
    int found = 0;
    for (i = 0; i < V; i++)
    {
        if (articulation[i])
        {
            printf("Router %d\n", i);
            found = 1;
        }
    }
    
    if (!found)
        printf("No articulation points found.\n");
}

int main()
{
    int V, E, i;
    int adj[MAX][MAX] = {0};  // Adjacency matrix initialized to 0
    int u, v;
    
    printf("Enter the number of routers (vertices): ");
    scanf("%d", &V);
    
    printf("Enter the number of connections (edges): ");
    scanf("%d", &E);
    
    printf("Enter the connections (u v) - routers numbered from 0 to %d:\n", V-1);
    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < V && v >= 0 && v < V)
        {
            adj[u][v] = 1;
            adj[v][u] = 1;  // Undirected graph
        }
        else
        {
            printf("Invalid router number! Ignoring edge %d %d\n", u, v);
        }
    }
    
    findArticulationPoints(adj, V);
    
    return 0;
}
