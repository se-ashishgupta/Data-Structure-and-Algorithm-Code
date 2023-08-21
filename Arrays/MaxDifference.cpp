#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int MaxDiffNaive(vector<int> &arr, int n) // Naive
{
    int res = arr[1] - arr[0];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            res = max(res, (arr[j] - arr[i]));
        }
    }

    return res;
}
int MaxDiff(vector<int> &arr, int n) // Naive
{
    int res = arr[1] - arr[0];
    int minVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        res = max(res, (arr[i] - minVal));
        minVal = min(minVal, arr[i]);
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 3, 10, 6, 4, 8, 1};
    int n = arr.size();
    cout << MaxDiff(arr, n);
    return 0;
}