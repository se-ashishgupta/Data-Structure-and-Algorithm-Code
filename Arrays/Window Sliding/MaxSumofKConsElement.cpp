#include <iostream>
#include <vector>
using namespace std;

int MaxSumKElementNaive(vector<int> &arr, int n, int k)
{

    int res = 0;
    for (int i = 0; i + k - 1 < n; i++)
    {
        int currSum = 0;
        for (int j = 0; j < k; j++)
        {
            currSum += arr[i + j];
        }
        res = max(res, currSum);
    }

    return res;
}
int MaxSumKElement(vector<int> &arr, int n, int k)
{

    int currSum = 0;
    for (int i = 0; i < k; i++)
    {
        currSum += arr[i];
    }
    int res = currSum;

    for (int i = k; i < n; i++)
    {
        currSum += arr[i] - arr[i - k];
        res = max(res, currSum);
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 8, 30, -5, 20, 7};
    int n = arr.size();
    int k = 3;
    cout << MaxSumKElement(arr, n, k);
    return 0;
}
