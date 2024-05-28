/*Output:


Enter the number of vertices: 4

Enter the adjacency matrix:
0 1 0 0
1 0 1 1
0 1 0 0
0 1 0 0

0->1
1->2
1->3

Graph is connected




*/



#include <stdio.h>

int a[20][20], reach[20], n;

void dfs(int v) {
    int i;
    reach[v] = 1;
    for (i = 0; i < n; i++) {
        if (a[v][i] && !reach[i]) {
            printf("\n%d->%d", v, i);
            dfs(i);
        }
    }
}

int main(void) {
    int i, j, count = 0;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        reach[i] = 0;
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    dfs(0);
    printf("\n");
    for (i = 0; i < n; i++) {
        if (reach[i])
            count++;
    }
    if (count == n)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected");
    return 0;
}
