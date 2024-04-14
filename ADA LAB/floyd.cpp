#include <iostream>
using namespace std;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void floyds(int distances[10][10], int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
}

int main()
{
    int distances[10][10], n;
    cout << "\nEnter the number of cities: ";
    cin >> n;
    cout << "\nEnter the distances between cities (use 999 for infinity):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> distances[i][j];
    floyds(distances, n);
    cout << "\nShortest paths between cities:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << distances[i][j] << "\t";
        cout <<"\n";
    }
    return 0;
}
