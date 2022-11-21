// Program for the adjacency list representation of a Graph

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void display(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int x : adj[i])
        {
            cout << x << " ";
        }

        cout << "\n";
    }
}

void DFSrec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";

    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            DFSrec(adj, u, visited);
        }
    }
}

void DFS(vector<int> adj[], int V, int s)
{
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSrec(adj, i, visited);
        }
    }
}

int main()
{
    int V = 4; // size of the vector

    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    display(adj, V);

    cout << "\n\n\n";
    DFS(adj, V, 0);
}