// DFS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector<vector<int>> &graph, int startNode)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    stack<int> stk;

    stk.push(startNode);

    while (!stk.empty())
    {
        int currentNode = stk.top();
        stk.pop();

        if (!visited[currentNode])
        {
            cout << currentNode << " ";
            visited[currentNode] = true;

            for (int i = numNodes - 1; i >= 0; --i)
            {
                if (graph[currentNode][i] && !visited[i])
                {
                    stk.push(i);
                }
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

    int startNode = 0; // Starting node for DFS traversal

    cout << "DFS Traversal starting from node " << startNode << ": ";
    DFS(graph, startNode);

    return 0;
}
