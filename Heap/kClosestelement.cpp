#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void kClosestElementNaive(int arr[], int n, int x, int k) // TC : O(nk)
{
    bool visited[n] = {false};
    for (int i = 0; i < k; i++)
    {
        int min_diff = INT16_MAX;
        int min_diff_indx;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && abs(arr[j] - x) <= min_diff)
            {
                min_diff = abs(arr[j] - x);
                min_diff_indx = j;
            }
        }
        cout << arr[min_diff_indx] << " ";
        visited[min_diff_indx] = true;
    }
}
void kClosestElement(int arr[], int n, int x, int k) // TC : O(nlogk)
{
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push({abs(arr[i] - x), i});
    }

    for (int i = k; i < n; i++)
    {
        int diff = abs(arr[i] - x);
        if (pq.top().first > diff)
        {
            pq.pop();
            pq.push({diff, i});
        }
    }

    while (pq.empty() == false)
    {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {10, 15, 7, 3, 4};
    kClosestElementNaive(arr, 5, 8, 2);

    return 0;
}
