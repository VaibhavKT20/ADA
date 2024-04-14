#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(vector<vector<int>> &graph, int startNode)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        int currentNode = q.front();
        cout << currentNode << " ";
        q.pop();

        for (int i = 0; i < numNodes; ++i)
        {
            if (graph[currentNode][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int numNodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;

    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            cin >> graph[i][j];
        }
    }

    int startNode;
    cout << "Enter the starting node for BFS traversal: ";
    cin >> startNode;

    cout << "BFS Traversal starting from node " << startNode << ": ";
    BFS(graph, startNode);

    return 0;
}
