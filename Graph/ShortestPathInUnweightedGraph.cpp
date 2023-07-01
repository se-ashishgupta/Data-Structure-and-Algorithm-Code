#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void shortestPath(vector<int> adj[], int v, int s) // TC:O(V+E)
{
    int dist[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT16_MAX;
    }

    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    dist[0] = 0;

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();

        for (int x : adj[curr])
        {
            if (visited[x] == false)
            {
                dist[x] = dist[curr] + 1;
                visited[x] = true;
                q.push(x);
            }
        }
    }

    for (int x : dist)
    {
        cout << x << " ";
    }
}

int main()
{
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    shortestPath(adj, v, 0);

    return 0;
}
