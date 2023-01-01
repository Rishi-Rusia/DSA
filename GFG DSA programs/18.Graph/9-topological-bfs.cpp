// Kahn's BFS based TOPOLOGICAL SORT

// In topological sorting we print the nodes with indegree "0" first
// and the nodes adjacent to them after these nodes have been printed
// The basic rule of Kahn's algorithm is that a node should only be printed
// once all the nodes sending indegree to it are printed already.

// To do this, we maintin and indegree list. With every element printed, we decrease
// the indegree of the element in the array. When the indegree of an element is 0,
// it is printed

// topological sorting can be done using DFS as well, this is the BFS implementation

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void BFS(vector<int> adj[], int indegree[], int visited[], int V)
{
    queue<int> q;

    for (int j = 0; j < V; j++)
    {
        if (indegree[j] == 0)
        {
            q.push(j);
            visited[j] = 1;
        }
    }

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (int x : adj[u])
        {
            indegree[x]--;
        }

        cout << u << " ";

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0 && visited[i] == false)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void BFSdis(vector<int> adj[], int V, int indegree[])
{
    int visited[V] = {0};

    BFS(adj, indegree, visited, V);
}

void addEdge(vector<int> adj[], int u, int v, int indegree[])
{
    adj[u].push_back(v);

    indegree[v]++;
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
    vector<int> adj[5];
    int V = 5;
    int indegree[5] = {0};

    addEdge(adj, 0, 1, indegree);
    addEdge(adj, 1, 2, indegree);
    addEdge(adj, 3, 4, indegree);
    addEdge(adj, 3, 2, indegree);

    graphPrint(adj, V);

    cout << endl
         << endl;

    for (int x : indegree)
    {
        cout << x << " ";
    }

    cout << endl;
    cout << endl;

    BFSdis(adj, V, indegree);
}