#include <iostream>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void warshall(int p[10][10], int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                p[i][j] = max(p[i][j], p[i][k] && p[k][j]);
}
int main()
{
    int p[10][10], n;
    cout << "\n Enter the number of vertices:";
    cin >> n;
    cout << "\n Enter the distances between edges:\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> p[i][j];
    warshall(p, n);
    cout << "\n Transitive closure: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << p[i][j] << "\t";
        cout << "\n";
    }
    return 0;
}