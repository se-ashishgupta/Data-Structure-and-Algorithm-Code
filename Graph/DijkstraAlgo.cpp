#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dijkstraAlgo(vector<int> graph[], int V, int src)
{
    vector<int> dist(V, INT16_MAX);
    dist[src] = 0;
    vector<bool> fin(V, false);

    for (int i = 0; i < V - 1; i++)
    {
        int u = -1;
        for (int j = 0; j < V; j++)
        {
            if (!fin[j] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        fin[u] = true;
        for (int k = 0; k < V; k++)
        {
            if (graph[u][k] != 0 && fin[k] == false)
                dist[k] = min(dist[k], dist[u] + graph[u][k]);
        }
    }
    return dist;
}

int main()
{

    int v = 6;
    vector<int> graph[v];
    graph[0] = {0, 50, 100, 0};
    graph[1] = {50, 0, 30, 200};
    graph[2] = {100, 30, 0, 20};
    graph[3] = {0, 200, 20, 0};
    vector<int> res = dijkstraAlgo(graph, 4, 0);
    for (int x : res)
        cout << x << " ";
    return 0;
}