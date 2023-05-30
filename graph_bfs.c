    #include<stdio.h>

    #include<conio.h>

    int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

    void bfs(int v) {

        for (i = 1; i <= n; i++)

            if (a[v][i] && !visited[i])

                q[++r] = i;

        if (f <= r) {

            visited[q[f]] = 1;

            bfs(q[f++]);

        }

    }

    int main(int argc, char **argv) {

        int v = 1, count = 0;

        printf("\n Enter the number of vertices:");

        scanf("%d", &n);

        for (i = 1; i <= n; i++) {

            q[i] = 0;

            visited[i] = 0;

        }

        printf("\n Enter graph data in matrix form:\n");

        for (i = 1; i <= n; i++)

            for (j = 1; j <= n; j++)

                scanf("%d", &a[i][j]);

        bfs(v);

        for (i = 1; i <= n; i++)

            if (visited[i])

                count++;

        if (count == n)

            printf("\n Graph is connected");

        else

            printf("\n Graph is not connected");

        return 0;

    }
