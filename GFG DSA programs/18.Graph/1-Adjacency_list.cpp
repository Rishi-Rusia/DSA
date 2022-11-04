// Program for the adjacency list representation of a Graph

#include <iostream>
#include <vector>

using namespace std;

// Function to add edges to graph

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print graph
void display(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " => ";
        for (int x : adj[i])
        {
            cout << x << " ";
        }

        cout << "\n";
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
}