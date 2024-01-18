#include <iostream>
int min(int a, int b)
{
    return (a < b) ? a : b;
}
void floyds(int distances[10][10], int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
}
int main()
{
    int distances[10][10], n;
    std::cout << "\n Enter the number of cities:";
    std::cin >> n;
    std::cout << "\n Enter the distances between cities (use 999 for infinity):\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> distances[i][j];
    floyds(distances, n);
    std::cout << "\n Shortest paths between cities:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            std::cout << distances[i][j] << "\t";
        std::cout << "\n";
    }
    return 0;
}