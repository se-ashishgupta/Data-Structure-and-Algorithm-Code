#include <iostream>
#include <deque>
using namespace std;

void printMaxNaive(int arr[], int n, int k)
{
    for (int i = 0; i < n - k + 1; i++)
    {
        int mx = arr[i];
        for (int j = i + 1; j < i + k; j++)
        {
            mx = max(arr[j], mx);
        }
        cout << mx << " ";
    }
}
void printMax(int arr[], int n, int k)
{

    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
}
int main()
{
    int arr[] = {20, 40, 30, 10, 60};
    int n = 5;
    int k = 3;
    printMaxNaive(arr, n, k);
    return 0;
}