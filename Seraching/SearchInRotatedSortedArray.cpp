#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMin(vector<int> &arr, int l, int h)
{

    while (l < h)
    {

        int mid = l + (h - l) / 2;

        if (arr[mid] > arr[h])
        {

            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }

    return h;
}

int binarySearch(vector<int> &arr, int l, int h, int target)
{

    while (l <= h)
    {

        int mid = l + (h - l) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
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

int findtriplet(vector<int> &arr, int n, int target)
{
    int pivot = findMin(arr, 0, n - 1);

    int res1 = binarySearch(arr, 0, pivot - 1, target);

    if (res1 != -1)
        return res1;

    return binarySearch(arr, pivot, n - 1, target);
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 8, 9};
    int n = arr.size();
    int target = 30;

    cout << findtriplet(arr, n, target);

    return 0;
}