#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsRec(vector<int> adj[], int s, bool visited[])
{

    visited[s] = true;
    cout << s << " ";

    for (int x : adj[s])
    {
        if (visited[x] == false)
            dfsRec(adj, x, visited);
    }
}

void dfs(vector<int> adj[], int v, int s)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    dfsRec(adj, s, visited);
}
int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    dfs(adj, v, 0);

    return 0;
}