#include <iostream>
#include <vector>
using namespace std;

int MaxLengthEvenOddSubarrayNaive(vector<int> &arr, int n)
{
    int res = 1;

    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] % 2 == 0 && arr[j - 1] % 2 != 0)
            {
                curr++;
            }
            else if (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0)
            {
                curr++;
            }
            res = max(res, curr);
        }
    }

    return res;
}

int MaxLengthEvenOddSubarray(vector<int> &arr, int n) // Kadane Algorithm
{
    int res = 1;
    int curr = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            curr++;
            res = max(curr, res);
        }
        else
        {
            curr = 1;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {10, 12, 14, 7, 8};
    int n = arr.size();
    cout << MaxLengthEvenOddSubarray(arr, n);
    return 0;
}
