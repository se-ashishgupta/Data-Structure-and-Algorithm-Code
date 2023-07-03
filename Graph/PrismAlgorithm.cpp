#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void prismAlgo(vector<pair<int, int>> adj[], int v)
{
}

int main()
{

    int v = 6;
    vector<int> graph[v];
    graph[0] = {0, 5, 10, 0};
    graph[1] = {5, 0, 3, 20};
    graph[2] = {10, 3, 0, 2};
    graph[3] = {0, 20, 2, 0};

    return 0;
}