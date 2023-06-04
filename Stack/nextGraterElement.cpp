#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
void nextGratElementNaive(int arr[], int n) // TC: O(n*n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }
        if (j == n)
            cout << -1 << " ";
    }
}
void nextGratElement(int arr[], int n) // TC: O(n)
{
    stack<int> s;
    vector<int> v;
    v.push_back(-1);
    s.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && s.top() <= arr[i])
        {
            s.pop();
        }
        int pg = s.empty() ? -1 : s.top();
        v.push_back(pg);
        s.push(arr[i]);
    }

    reverse(v.begin(), v.end());
    for (auto x : v)
        cout << x << " ";
}
int main()
{
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    int n = 8;
    nextGratElement(arr, n);
    return 0;
}
