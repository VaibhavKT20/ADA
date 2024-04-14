#include <stdio.h>
int min, cost[100][100], parent[100], x, y, n;
int check_cycle(int x, int y)
{
    if ((parent[x] == parent[y]) && parent[x] != 0)
    {
        return 0;
    }
    else if (parent[x] == parent[y])
    {
        parent[x] = parent[y] = x;
    }
    else if (parent[x] == 0)
    {
        parent[x] = parent[y];
    }
    else if (parent[x] != parent[y])
    {
        parent[y] = parent[x];
    }
    return 1;
}
void find_min()
{
    min = 999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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

int main()
{
    int count = 0, tot = 0, flag;
    printf("Enter the size of verties: ");
    scanf("%d", &n);
    printf("Enter the matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            parent[j] = 0;
        }
    }
    while (count != n - 1 && min != 999)
    {
        find_min();
        flag = check_cycle(x, y);
        if (flag == 1)
        {
            printf("%d------->%d==%d\n", x, y, cost[x][y]);
            count++;
            tot = tot + cost[x][y];
        }
        cost[x][y] = cost[y][x] = 999;
    }
    printf("Cost of minimum spanning tree is %d\n", tot);
    return 0;
}