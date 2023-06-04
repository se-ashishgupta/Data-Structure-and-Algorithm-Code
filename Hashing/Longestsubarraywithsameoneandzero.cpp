#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int LongestSubArraywithsamezeroandone(int arr[], int n) // O(n)
{
    unordered_map<int, int> m;
    int res = 0;
    int prefSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (prefSum == 0)
            res = i + 1;
        prefSum += arr[i];
        if (m.find(prefSum) == m.end())
        {
            m.insert({{arr[i], i}});
        }
        if (m.find(prefSum) != m.end())
            res = max(res, i - m[prefSum]);
    }
    return res;
}

int LongestSubArraywithsamezeroandoneNaive(int arr[], int n) // O(n*n)
{

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int zero = 0, one = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                zero++;
            else
                +one++;
            if (zero == one)
                res = max(res, j - i + 1);
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << LongestSubArraywithsamezeroandone(arr, size);
    return 0;
}