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

void levelOrder(vector<int> adj[], int V, int s)
{
    bool visited[V + 1];
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    q.push(s);
    visited[s] = true;

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int x : adj[u])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    cout << "\n";
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
    levelOrder(adj, V, 0);
}