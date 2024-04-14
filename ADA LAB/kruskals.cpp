#include <iostream>
#include <ctime>
using namespace std;

int min_value, cost[100][100], parent[100], n, x, y;

void find_min()
{
    min_value = 999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] < min_value && cost[i][j] != 0)
            { // Ensure not to select self loops (cost 0)
                min_value = cost[i][j];
                x = i;
                y = j;
            }
        }
    }
}

int find_set(int i)
{
    while (parent[i] != -1)
        i = parent[i];
    return i;
}

int union_set(int i, int j)
{
    int u = find_set(i);
    int v = find_set(j);
    if (u != v)
    {
        parent[u] = v;
        return 1;
    }
    return 0;
}

int main()
{

    int count = 0, tot = 0, flag = 0;
    cout << "Enter the number of vertices: " << endl;
    cin >> n;
    cout << "Enter the cost matrix: " << endl;
    cout << "Enter 999 for No edges and self loops" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
        parent[i] = -1; // Initialize each vertex to its own set
    }

    clock_t start, end;
    start = clock();
    while (count != n - 1 && min_value != 999)
    {
        find_min();
        flag = union_set(x, y); // Union two sets
        if (flag == 1)
        {
            cout << x << "----->" << y << "==" << cost[x][y] << endl;
            count++;
            tot += cost[x][y];
        }
        cost[x][y] = cost[y][x] = 999;
    }
    cout << "\nThe total cost of minimum spanning tree: " << tot << endl;

    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time spent: " << time_spent << " seconds" << endl;

    return 0;
}
