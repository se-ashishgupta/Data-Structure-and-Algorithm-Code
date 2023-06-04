#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int LongestSubArraywithGivensum(int arr[], int n, int sum) // O(n)    AS:O(n)
{
    unordered_map<int, int> s;
    int prefSum = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        prefSum += arr[i];
        if (prefSum == sum)
            res = i + 1;
        if (s.find(prefSum) == s.end())
            s.insert({prefSum, i});

        if (s.find(prefSum - sum) != s.end())
        {
            res = max(res, i - s[prefSum - sum]);
        }
    }
    return res;
}

int LongestSubArraywithGivensumNaive(int arr[], int n, int sum) // O(n*n)
{
    int longest = 0;
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];

            if (currSum == sum)
            {
                longest = max(longest, j - i + 1);
            }
        }
    }
    return longest;
}
int main()
{
    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 4;
    cout << LongestSubArraywithGivensum(arr, size, sum);
    return 0;
}