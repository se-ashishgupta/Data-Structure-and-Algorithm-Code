#include <iostream>
#include <algorithm>
using namespace std;

int minDiff(int arr[], int n)
{
    int res = INT16_MAX;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            res = min(res, abs(arr[i] - arr[j]));
        }
    }
    return res;
}

// int minDiff(int arr[], int n)
// {
//     sort(arr, arr + n);
//     int res = INT16_MAX;
//     for (int i = 1; i < n; i++)
//     {
//         res = min(res, arr[i] - arr[i - 1]);
//     }
//     return res;
// }
int main()
{
    int arr[] = {10, 8, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minDiff(arr, n);

    return 0;
}