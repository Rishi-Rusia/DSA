#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void display(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "->";
        for (int x : adj[i])
        {
            cout << x << " ";
        }

        cout << "\n";
    }
}

void PrintStack(stack<int> s)
{
    // If stack is empty
    if (s.empty())
        return;

    // Extract top of the stack
    int x = s.top();

    // Pop the top element
    s.pop();

    // Print the current top
    // of the stack i.e., x
    cout << x << ' ';

    // Proceed to print
    // remaining stack
    PrintStack(s);

    // Push the element back
    s.push(x);
}

void DFSrec(vector<int> adj[], int s, bool visited[], stack<int> &st)
{
    visited[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            DFSrec(adj, u, visited, st);
        }
    }

    st.push(s);
}

void DFS(vector<int> adj[], int V, int s)
{
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSrec(adj, i, visited, st);
        }
    }

    PrintStack(st);
}

int main()
{
    int V = 5; // size of the vector

    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 3);

    display(adj, V);

    cout << "\n\n\n";
    DFS(adj, V, 0);
}