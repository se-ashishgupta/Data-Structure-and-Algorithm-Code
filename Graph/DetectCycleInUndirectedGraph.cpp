#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool DFSREC(vector<int> adj[], int s, bool visited[], int parent) // TC:O(V+E)
{

    visited[s] = true;
    for (int x : adj[s])
    {
        if (visited[x] == false)
        {
            if (DFSREC(adj, x, visited, s) == true)
                return true;
        }
        else if (x != parent)
            return true;
    }
    return false;
}

bool detectCycle(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (DFSREC(adj, i, visited, -1) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    cout << detectCycle(adj, v);

    return 0;
}
