// Cycle in Directed Graph using Depth First Search

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool DFSrec(vector<int> adj[], int s, int visited[], int recSt[])
{
    visited[s] = true;
    recSt[s] = true;

    for (int x : adj[s])
    {
        if (visited[x] == false && DFSrec(adj, x, visited, recSt))
        {
            return true;
        }
        else if (recSt[x] == true)
        {
            return true;
        }
    }
    recSt[s] = false;
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    int visited[V] = {0, 0, 0, 0, 0, 0};
    int recSt[V] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (DFSrec(adj, i, visited, recSt) == true)
            {
                return true;
            }
        }
    }

    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void graphPrint(vector<int> adj[], int V)
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

int main()
{
    vector<int> adj[6];
    int V = 6;

    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    graphPrint(adj, 6);

    if (DFS(adj, V))
    {
        cout << "Cylic graph";
    }
    else
    {
        cout << "no";
    }
}