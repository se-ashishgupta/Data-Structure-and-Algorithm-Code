#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int LongestCommonsapnwithsamesumintwobinaryarray(int arr[], int arr1[], int n) // O(n)
{
    int res = 0;
    unordered_map<int, int> m;
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i] - arr1[i];
    }
    int prefSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefSum += arr[i];
        if (prefSum == 0)
            res = i + 1;
        if (m.find(prefSum) == m.end())
            m.insert({prefSum, i});

        if (m.find(prefSum) != m.end())
        {
            res = max(res, i - m[prefSum]);
        }
    }
    return res;
}

int LongestCommonsapnwithsamesumintwobinaryarrayNaive(int arr[], int arr1[], int n) // TC: O(n*n)         AS:O(1)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int sum1 = 0, sum2 = 0;
        for (int j = i; j < n; j++)
        {
            sum1 += arr[j];
            sum2 += arr1[j];
            if (sum1 == sum2)
            {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}
int main()
{
    int arr[] = {0, 1, 0, 0, 0, 0};
    int arr1[] = {1, 0, 1, 0, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << LongestCommonsapnwithsamesumintwobinaryarray(arr, arr1, size);
    return 0;
}