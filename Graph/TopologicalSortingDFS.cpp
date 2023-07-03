#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void dfs(vector<int> adj[], int s, bool visited[], stack<int> &st) // TC :O(V+E) is only fro acyclic graph
{

    visited[s] = true;
    for (int x : adj[s])
    {
        if (visited[x] == false)
            dfs(adj, x, visited, st);
    }
    st.push(s);
}
void topologicalSorting(vector<int> adj[], int v)
{
    bool visited[v];
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
        cout << st.top() << " ";
        st.pop();
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