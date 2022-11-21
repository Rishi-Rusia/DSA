// Graph Introduction and BFS

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void addEdge(vector<int> adj[], int v, int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void display(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "=>";
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void BFS(vector<int> adj[], int V, int visited[], int s)
{
    queue<int> q;

    q.push(s);
    visited[s] = 1;

    while (q.empty() == false)
    {
        int temp = q.front();
        q.pop();

        for (int x : adj[temp])
        {
            if (visited[x] == 0)
            {
                visited[x] = 1;
                q.push(x);
            }
        }

        cout << temp << " ";
    }
}

void BFSdis(vector<int> adj[], int V, int visited[])
{
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            BFS(adj, V, visited, i);
        }
    }
}

int main()
{
    int V = 7;

    vector<int> adj[V];
    int visited[V] = {0};

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 6);
    addEdge(adj, 6, 5);

    display(adj, V);
    cout << endl;
    BFS(adj, V, visited, 0);
    BFSdis(adj, V, visited);
}