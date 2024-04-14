#include <iostream>
using namespace std;

int minVal, cost[100][100], parent[100], n, x, y;

void find_min()
{
    minVal = 999;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (cost[i][j] < minVal)
            {
                minVal = cost[i][j];
                x = i;
                y = j;
            }
}

int check_cycle(int x, int y)
{
    if ((parent[x] == parent[y]) && (parent[x] != 0))
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
    cout << "Enter the number of vertices: " << endl;
    cin >> n;
    cout << "Enter the cost matrix:" << endl;
    cout << "Enter 999 for No edges and self loops:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            parent[j] = 0;
        }
    }
    while (count != n - 1 && minVal != 999)
    {
        find_min();
        flag = check_cycle(x, y);
        if (flag == 1)
        {
            cout << x << "----->" << y << "==" << cost[x][y] << endl;
            count++;
            tot += cost[x][y];
        }
        cost[x][y] = cost[y][x] = 999;
    }
    cout << "\nThe total cost of minimum spanning tree= " << tot;

    return 0;
}
