// BFS

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
    int numNodes = 6; // Number of nodes in the graph
    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    // Example graph representation (adjacency matrix)
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][4] = 1;
    graph[3][5] = 1;
    graph[4][5] = 1;

    int startNode = 0; // Starting node for BFS traversal

    cout << "BFS Traversal starting from node " << startNode << ": ";
    BFS(graph, startNode);

    return 0;
}
