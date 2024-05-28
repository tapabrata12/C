/* Output:

The maximum possible flow is 23


*/



#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 6

// Function to find augmenting path using DFS
bool dfs(int rGraph[V][V], int s, int t, int parent[]) {
  // Create a visited array and mark all vertices as not visited
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Create a stack, push the source vertex, and mark it as visited
  int stack[V];
  int top = -1;
  stack[++top] = s;
  visited[s] = true;
  parent[s] = -1;

  // DFS traversal
  while (top >= 0) {
    int u = stack[top--];
    for (int v = 0; v < V; v++) {
      if (!visited[v] && rGraph[u][v] > 0) {
        stack[++top] = v;
        parent[v] = u;
        visited[v] = true;
      }
    }
  }

  // If sink is visited after DFS, then there is a path from source to sink
  return visited[t];
}

// Ford-Fulkerson algorithm
int fordFulkerson(int graph[V][V], int s, int t) {
  int rGraph[V][V]; // Residual graph
  for (int u = 0; u < V; u++)
    for (int v = 0; v < V; v++)
      rGraph[u][v] = graph[u][v];

  int parent[V]; // Array to store augmenting path

  int maxFlow = 0; // Initialize maximum flow

  // Augment the flow while there is a path from source to sink
  while (dfs(rGraph, s, t, parent)) {
    // Find minimum residual capacity of the edges along the path filled by DFS.
    int pathFlow = INT_MAX;
    for (int v = t; v != s; v = parent[v]) {
      int u = parent[v];
      pathFlow = (pathFlow < rGraph[u][v]) ? pathFlow : rGraph[u][v];
    }

    // Update residual capacities of the edges and reverse edges along the path
    for (int v = t; v != s; v = parent[v]) {
      int u = parent[v];
      rGraph[u][v] -= pathFlow;
      rGraph[v][u] += pathFlow;
    }

    // Add path flow to overall flow
    maxFlow += pathFlow;
  }

  return maxFlow;
}

// Driver program to test above functions
int main() {
  // Sample graph
  int graph[V][V] = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0},
                     {0, 4, 0, 0, 14, 0},  {0, 0, 9, 0, 0, 20},
                     {0, 0, 0, 7, 0, 4},   {0, 0, 0, 0, 0, 0}};

  int source = 0, sink = 5;
  printf("The maximum possible flow is %d\n",
         fordFulkerson(graph, source, sink));

  return 0;
}