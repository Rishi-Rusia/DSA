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

void BFS(vector<int> adj[], int dist[], int visited[], int s)
{
    queue<int> q;

    q.push(s);
    dist[s] = 0;
    visited[s] = true;

    while (q.empty() == false)
    {
        int u = q.front();

        q.pop();

        for (int x : adj[u])
        {
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
                dist[x] = dist[u] + 1;
            }
        }

        cout << u << " ";
    }
}

int main()
{
    vector<int> adj[4];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 3);

    int dist[4] = {0};

    int visited[4] = {0};

    BFS(adj, dist, visited, 0);

    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << dist[i] << " ";
    }
}
