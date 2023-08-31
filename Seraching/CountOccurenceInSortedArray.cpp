#include <iostream>
#include <vector>
using namespace std;
int m;
// int firstOccurance(vector<int> &arr, int l, int h, int target)
// {

//     while (l <= h)
//     {
//         int mid = l + (h - l) / 2;

//         if (arr[mid] > target)
//         {
//             h = mid - 1;
//         }
//         else if (arr[mid] < target)
//         {
//             l = mid + 1;
//         }
//         else
//         {

//             if (mid == 0 || arr[mid - 1] != arr[mid])
//             {
//                 return mid;
//             }
//             else
//             {
//                 h = mid - 1;
//             }
//         }
//     }

//     return -1;
// }

// int lastOccurance(vector<int> &arr, int l, int h, int target)
// {

//     while (l <= h)
//     {
//         int mid = l + (h - l) / 2;

//         if (arr[mid] > target)
//         {
//             h = mid - 1;
//         }
//         else if (arr[mid] < target)
//         {
//             l = mid + 1;
//         }
//         else
//         {

//             if (mid == m - 1 || arr[mid + 1] != arr[mid])
//             {
//                 return mid;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }
//     }

//     return -1;
// }

int binarySeacrh(vector<int> &arr, int l, int h, int x)
{

    while (l <= h)
    {

        int mid = l + (h - l) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return -1;
}

int countOcuu(vector<int> &arr, int n, int x)
{
    int idx = binarySeacrh(arr, 0, n - 1, x);
    if (idx == -1)
        return -1;

    int count = 1;
    int i = idx - 1;

    while (i >= 0 && arr[i] == arr[idx])
    {
        count++;
        i--;
    }

    i = idx + 1;
    while (i < n && arr[i] == arr[idx])
    {
        count++;
        i++;
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 10, 10, 10, 10, 20, 30, 40};
    int n = arr.size();
    m = n;
    int target = 10;
    // int res = firstOccurance(arr, 0, n - 1, target);
    // if (res == -1)
    //     cout << -1;
    // else
    //     cout << lastOccurance(arr, 0, n - 1, target) - res + 1;
    cout << countOcuu(arr, n, target);
    return 0;
}