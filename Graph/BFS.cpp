#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[], int v, int s)
{

    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

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
int main()
{
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    bfs(adj, v, 0);

    return 0;
}