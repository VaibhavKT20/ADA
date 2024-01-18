{
    int min = 999;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[x][y] < min)
            {
                min = cost[x][y];
                x = i;
                y = j;
            }
        }
    }
}

int main()
{
    int count = 0, tot = 0, flag = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the cost of matrix:");
    printf("\nEnter 999 for self joining vetex or infinte vertex: ");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[x][y]);
            parent[j] = 0;
        }
    }
    while (count != n - 1 && min != 999)
    {