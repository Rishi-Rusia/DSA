#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{

    for (int i = 0; i < V; i++)
    {
        cout << i << "->";

        for (int x : adj[i])
        {
            cout << x << " ";
        }

        cout << endl;
    }
}

bool DFSrec(vector<int> adj[], int visited[], int source, int parent)
{
    visited[source] = true;

    for (int x : adj[source])
    {
        if (visited[x] == false)
        {
            if (DFSrec(adj, visited, x, source) == true)
            {
                return true;
            }
        }
        else if (x != parent)
        {
            return true;
        }
    }

    return false;
}

bool DFS(vector<int> adj[], int V, int source)
{
    int visited[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (DFSrec(adj, visited, source, -1) == true)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> adj[4];

    int V = 4;

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 0);

    printGraph(adj, V);

    cout << DFS(adj, V, 0);
}