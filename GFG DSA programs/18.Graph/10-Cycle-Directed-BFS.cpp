// CYCLE DETECTION ALGORITHM FOR DIRECTED GRAPH USING BFS

// This program is a modification of Kahn's algorithm in which vertices are printed according to indegree
// In this program we run the Kahn's algorithm and count all the vertices while doing it
// If the cycle is present, the count will not be equal to the original size of the adj list (V)
// otherwise they'll be equal

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool BFS(vector<int> adj[], int indegree[], int visited[], int V)
{
    queue<int> q;
    int count = 0;

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

        // cout << u << " ";

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0 && visited[i] == false)
            {
                q.push(i);
                visited[i] = 1;
            }
        }

        count++;
    }

    return (count != V);
}

bool BFSdis(vector<int> adj[], int V, int indegree[])
{
    int visited[V] = {0};

    return BFS(adj, indegree, visited, V);
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
    addEdge(adj, 2, 0, indegree);
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

    if (BFSdis(adj, V, indegree))
    {
        cout << "Cycle present";
    }
    else
    {
        cout << "Cycle not present";
    }
}