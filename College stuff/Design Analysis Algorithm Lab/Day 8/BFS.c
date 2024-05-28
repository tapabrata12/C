/*Output:

Enter the number of vertices: 4

Enter graph data in Matrix form:
0 1 1 1
0 0 0 1
0 0 0 0
0 0 1 0
Enter starting vertex: 1
The reachable nodes are: 2      3       4

*/

#include <stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
    for (i = 0; i < n; i++) {
        if (a[v][i] && !visited[i]) {
            q[++r] = i;
            visited[i] = 1;
        }
    }
    if (f <= r) {
        bfs(q[f++]);
    }
}

int main(void) {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n); 
    printf("\nEnter graph data in Matrix form: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &v);
    bfs(v);
    printf("The reachable nodes are: ");
    for (i = 0; i < n; i++) {
        if (visited[i]) {
            printf("%d\t", i);
        }
    } 
    return 0;
}