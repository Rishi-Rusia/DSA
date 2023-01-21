// PROGRAM FOR KOSARAJU's ALGORITHM WAS NOT PROVIDED

// STUDY THE ALGORITHM ONCE AGAIN AND CODE IT

// THE CODE BELOW WAS WRITTEN BY CHATGPT

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int v, vector<int> adj[], vector<bool> &visited, stack<int> &s)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            DFS(u, adj, visited, s);
        }
    }
    s.push(v);
}

void DFS_transpose(int v, vector<int> adj_t[], vector<bool> &visited)
{
    visited[v] = true;
    cout << v << " ";
    for (int u : adj_t[v])
    {
        if (!visited[u])
        {
            DFS_transpose(u, adj_t, visited);
        }
    }
}

void kosaraju(vector<int> adj[], vector<int> adj_t[], int V)
{
    vector<bool> visited(V, false);
    stack<int> s;

    // First phase: DFS traversal of the graph
    for (int v = 0; v < V; v++)
    {
        if (!visited[v])
        {
            DFS(v, adj, visited, s);
        }
    }

    // Second phase: DFS traversal of the transpose
    fill(visited.begin(), visited.end(), false);
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        if (!visited[v])
        {
            DFS_transpose(v, adj_t, visited);
            cout << endl;
        }
    }
}

int main()
{
    int V = 8;
    vector<int> adj[V] = {{1, 2}, {3}, {2}, {4}, {5}, {5}, {6, 7}, {7}};
    vector<int> adj_t[V] = {{4}, {0, 5}, {0, 3}, {2}, {1}, {4, 6}, {7}, {6}};

    kosaraju(adj, adj_t, V);

    return 0;
}
