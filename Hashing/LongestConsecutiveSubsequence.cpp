#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int LongestConsecutiveSubsequence(int arr[], int n) // O(n)    AS:O(n)
{
    int res = 1;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            int curr = 1;

            while (s.find(arr[i] + curr) != s.end())
            {
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}

int LongestConsecutiveSubsequenceNaive(int arr[], int n) // O(nlogn)
{
    sort(arr, arr + n);
    int res = 1, curr = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
            curr++;
        else
        {
            res = max(res, curr);
            curr = 1;
        }
    }
    res = max(res, curr);
    return res;
}
int main()
{
    int arr[] = {8, 20, 7, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << LongestConsecutiveSubsequence(arr, size);
    return 0;
}