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
    cout << "Enter the starting node for DFS traversal: ";
    cin >> startNode;

    cout << "DFS Traversal starting from node " << startNode << ": ";
    DFS(graph, startNode);

    return 0;
}
