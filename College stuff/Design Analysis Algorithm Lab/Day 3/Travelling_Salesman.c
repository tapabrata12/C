#include <stdio.h>

#define INF 999999
#define N 4

void copy_array(int n, int src[n], int dest[n]) {
  for (int i = 0; i < n; i++)
    dest[i] = src[i];
}

int first_unvisited(int n, int visited[n]) {
  for (int i = 0; i < n; i++)
    if (!visited[i])
      return i;
  return -1;
}

void tsp(int n, int graph[n][n], int v, int visited[n], int nodes_visited,
         int path[n], int path_index, int *minpath, int *min_distance) {
  visited[v] = 1;
  nodes_visited++;
  path[path_index++] = v;

  if (nodes_visited == n) {
    int curr_path_weight = 0;
    for (int i = 0; i < path_index - 1; i++) {
      curr_path_weight += graph[path[i]][path[i + 1]];
    }
    curr_path_weight += graph[path[path_index - 1]][path[0]];

    if (curr_path_weight < *min_distance) {
      *min_distance = curr_path_weight;
      copy_array(n, path, minpath);
    }
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      tsp(n, graph, i, visited, nodes_visited, path, path_index, minpath,
          min_distance);
    }
  }

  visited[v] = 0;
}

int main() {
  int graph[N][N] = {
      {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
  int visited[N];
  for (int i = 0; i < N; i++)
    visited[i] = 0;

  int path[N];
  int minpath[N];
  for (int i = 0; i < N; i++)
    minpath[i] = -1;

  int min_distance = INF;
  tsp(N, graph, 0, visited, 0, path, 0, minpath, &min_distance);

  printf("Minimum distance : %d\n", min_distance);
  printf("Path Taken : ");
  for (int i = 0; i < N; i++)
    printf("%d ", minpath[i]);

  return 0;
}
