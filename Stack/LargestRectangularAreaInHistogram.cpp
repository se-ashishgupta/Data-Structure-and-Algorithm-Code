#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> printPrevSmaller(int arr[], int n) // TC: O(n)
{
    stack<int> s;
    vector<int> pge;
    pge.push_back(-1);
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        int pg = s.empty() ? -1 : s.top();
        pge.push_back(pg);
        s.push(i);
    }
    return pge;
}
vector<int> nextSmallerElement(int arr[], int n) // TC: O(n)
{
    stack<int> s;
    vector<int> nge;
    nge.push_back(n);
    s.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        int pg = s.empty() ? n : s.top();
        nge.push_back(pg);
        s.push(i);
    }

    reverse(nge.begin(), nge.end());

    return nge;
}

int getMaxAreaNaive(int arr[], int n) // TC: O(n*n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
                curr += arr[i];
            else
                break;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
                curr += arr[i];
            else
                break;
        }
        res = max(res, curr);
    }
    return res;
}

int getMaxArea(int arr[], int n) // TC: O(n)
{

    vector<int> pg = printPrevSmaller(arr, n);
    vector<int> ng = nextSmallerElement(arr, n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        curr += (i - pg[i] - 1) * arr[i];
        curr += (ng[i] - i - 1) * arr[i];
        res = max(res, curr);
    }
    return res;
}

int getMaxArea1(int arr[], int n) // TC: O(n) One Traversal and one stack
{

    stack<int> s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }
    while (s.empty() == false)
    {
        int tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int arr[] = {10, 5, 20, 2};
    int n = 4;
    cout << getMaxArea1(arr, n);
    return 0;
}
