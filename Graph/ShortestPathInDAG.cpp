#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
}
void dfs(vector<pair<int, int>> adj[], int v, bool visited[], stack<int> &st) // TC :O(V+E) is only fro acyclic graph
{

    visited[v] = true;
    for (auto x : adj[v])
    {
        if (visited[x.first] == false)
            dfs(adj, x.first, visited, st);
    }
    st.push(v);
}

void topologicalSorting(vector<pair<int, int>> adj[], int v)
{
    bool visited[v];
    vector<int> topological;
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            dfs(adj, i, visited, st);
    }
    while (st.empty() == false)
    {
        int r = st.top();
        topological.push_back(r);
        st.pop();
    }
    vector<int> dist(v, INT32_MAX);
    dist[0] = 0;
    for (int x : topological)
    {
        for (auto y : adj[x])
        {
            int v = y.first;
            int weight = y.second;

            if (dist[x] + weight < dist[v])
                dist[v] = dist[x] + weight;
        }
    }

    for (int x : dist)
    {
        cout << x << " ";
    }
}

int main()
{

    int v = 6;
    vector<pair<int, int>> adj[v];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 4, 2, 2);
    addEdge(adj, 4, 5, 4);
    addEdge(adj, 2, 3, 6);
    addEdge(adj, 5, 3, 1);
    topologicalSorting(adj, v);
    return 0;
}