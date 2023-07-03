#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void topologicalSorting(vector<int> adj[], int v) // TC :O(V+E) also known as Khans Algorithm na dit is only fro acyclic graph
{
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (q.empty() == false)
    {

        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int x : adj[u])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
}
int main()
{

    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 4, 2);
    addEdge(adj, 4, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 5, 3);
    topologicalSorting(adj, v);
    return 0;
}