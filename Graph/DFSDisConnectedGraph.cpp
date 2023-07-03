#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsRec(vector<int> adj[], int s, bool visited[]) // TC: O(V+E)
{

    visited[s] = true;
    cout << s << " ";

    for (int x : adj[s])
    {
        if (visited[x] == false)
            dfsRec(adj, x, visited);
    }
}

void dfs(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            dfsRec(adj, i, visited);
    }
}
int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);

    dfs(adj, v);

    return 0;
}