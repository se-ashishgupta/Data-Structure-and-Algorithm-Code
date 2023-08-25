#include <iostream>
#include <vector>
using namespace std;

int MaxSumSubArrayNaive(vector<int> &arr, int n)
{
    int res = arr[0];

    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            res = max(res, curr);
        }
    }

    return res;
}

int MaxSumSubArray(vector<int> &arr, int n) // Kadane Algorithm
{
    int res = arr[0];
    int maxcurrending = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxcurrending = max(arr[i], maxcurrending + arr[i]);
        res = max(res, maxcurrending);
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    int n = arr.size();
    cout << MaxSumSubArray(arr, n);
    return 0;
}
