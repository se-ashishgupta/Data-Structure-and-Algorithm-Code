#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[], int s, bool visited[]) // TC: O(V+E)
{

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int v : adj[curr])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void bfsDis(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            bfs(adj, i, visited);
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
    bfsDis(adj, v);

    return 0;
}
