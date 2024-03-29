#include <iostream>
int min, cost[100][100], parent[100], i, j, x, y, n;

void find_min()
{
    min = 999;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                x = i;
                y = j;
            }
        }
    }
}

int check_cycle(int x, int y)
{
    if (parent[x] == parent[y] && parent[x] != 0)
        return 0;
    if (parent[x] == 0 && parent[y] == 0)
        parent[x] = parent[y] = x;
    else if (parent[x] == 0)
        parent[x] = parent[y];
    else if (parent[x] != parent[y])
        parent[y] = parent[x];
    return 1;
}

int main()
{
    int count = 0, tot = 0, flag = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            parent[j] = 0;
        }
    while (count != n - 1 && min != 999)
    {
        find_min();
        flag = check_cycle(x, y);
        if (flag == 1)
        {
            count++;
            tot += cost[x][y];
        }
        cost[x][y] = cost[y][x] = 999;
    }
    printf("\nThe total cost of minimum spanning tree=%d", tot);
    return 0;
}