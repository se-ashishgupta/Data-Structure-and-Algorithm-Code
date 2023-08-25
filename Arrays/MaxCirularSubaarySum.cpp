#include <iostream>
#include <vector>
using namespace std;

int MaxCirularSubaarySumNaive(vector<int> &arr, int n)
{
    int res = arr[0];

    for (int i = 0; i < n; i++)
    {
        int curr_max = arr[i];
        int curr_sum = arr[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            curr_sum += arr[index];
            curr_max = max(curr_max, curr_sum);
        }

        res = max(res, curr_max);
    }

    return res;
}

int kadne(vector<int> &arr, int n)
{

    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxEnding = max(arr[i], maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}
int MaxCirularSubaarySum(vector<int> &arr, int n) // Kadane Algorithm
{
    int normalMaxSubarraySum = kadne(arr, n);

    if (normalMaxSubarraySum < 0)
        return normalMaxSubarraySum;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        arr[i] = -arr[i];
    }

    int circularSumSubarray = sum + kadne(arr, n);

    return max(circularSumSubarray, normalMaxSubarraySum);
}

int main()
{
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    int n = arr.size();
    cout << MaxCirularSubaarySumNaive(arr, n);
    return 0;
}
