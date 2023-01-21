// DJIKSTRA

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> djikstra(vector<int> graph[], int V, int source)
{
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    vector<bool> fin(V, false);

    for (int count = 0; count < V - 1; count++)
    {

        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!fin[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }

        fin[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && fin[v] == false)
            {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }

    return dist;
}

int main()
{
    int V = 4;
    vector<int> adj[4] = {{0, 5, 10, 0}, {5, 0, 3, 20}, {10, 3, 0, 2}, {0, 20, 2, 0}};

    vector<int> result = djikstra(adj, V + 1, 0);

    for (int i = 0; i < V; i++)
    {
        cout << result[i] << " ";
    }
}

// Here's a step-by-step walkthrough of how the program would run:

// The V variable is initialized to 4, which represents the number of vertices in the graph. An array of 4 vectors is created, called adj, which represents the edges of the graph and their weights.

// The djikstra function is called with adj, V+1, and the source vertex 0.

// Inside the djikstra function, two vectors are created: dist and fin. The dist vector is initialized to have V elements, each set to INT_MAX, and the fin vector is initialized to have V elements, each set to false. The distance from the source vertex to itself is set to 0.

// The outer for loop runs V-1 times, which represents the number of iterations it takes to find the shortest path from the source vertex to all other reachable vertices.

// The first for-loop starts with the variable u being initialized to -1, then iterates through all vertices. It checks whether the vertex is visited or not by checking fin[i] and whether the distance from the source to that vertex is less than the distance from the source to u, if so update u with the current vertex.

// Once the vertex is chosen, mark it as visited by doing fin[u]=true;

// The inner for-loop starts, it also iterates through all vertices, and for each vertex v, if there is an edge between u and v and v is not yet visited, then check the distance between source and v through the chosen vertex u and if it shorter than the previous distance update it.

// The for-loop ends, and we return to the outer for-loop. Then the outer for-loop runs again V-1 times. And at the end of V-1 iterations, we have the shortest path from the source vertex to all other reachable vertices stored in the dist vector.

// After the djikstra function returns, the main function prints out the contents of the dist vector, which should be the shortest path from the source vertex to all other reachable vertices in the graph.

// The program ends.