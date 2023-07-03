#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool dfsRec(vector<int> adj[], int s, bool visited[], bool recSt[])
{
    visited[s] = true;
    recSt[s] = true;
    for (int x : adj[s])
    {
        if (visited[x] == false && dfsRec(adj, x, visited, recSt))
            return true;
        else if (recSt[x] == true)
            return true;
    }
    recSt[s] = false;
    return false;
}

bool dfs(vector<int> adj[], int v)
{

    bool visited[v], recSt[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        recSt[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            if (dfsRec(adj, i, visited, recSt) == true)
                return true;
    }
    return false;
}
int main()
{

    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);
    cout << dfs(adj, v);
    return 0;
}