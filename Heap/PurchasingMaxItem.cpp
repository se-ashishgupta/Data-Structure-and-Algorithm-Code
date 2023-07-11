#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int purchaseMaxItem(int arr[], int n, int sum) // TC : O(n) + O(res*logn)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int res = 0;

    while (pq.top() <= sum)
    {
        sum -= pq.top();
        res++;
        pq.pop();
    }
    return res;
};

int main()
{
    int arr[] = {20, 10, 5, 30, 100};
    cout << purchaseMaxItem(arr, 5, 35);

    return 0;
}
