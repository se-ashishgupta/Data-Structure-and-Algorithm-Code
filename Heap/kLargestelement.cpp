#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void kLargestElement(int arr[], int n, int k) // TC : O(n+klogn) MAX HEAP
{
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = 0; i < k; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
void kLargestElement1(int arr[], int n, int k) // TC : O(n+(n-k)logk) Min HEAP
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main()
{
    int arr[] = {20, 10, 5, 30, 100};
    kLargestElement1(arr, 5, 2);

    return 0;
}
