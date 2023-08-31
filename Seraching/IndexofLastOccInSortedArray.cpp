#include <iostream>
#include <vector>
using namespace std;
int m;
int lastOccurance(vector<int> &arr, int l, int h, int target)
{

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] > target)
        {
            h = mid - 1;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {

            if (mid == m - 1 || arr[mid + 1] != arr[mid])
            {
                return mid;
            }
            else
            {
                l = mid + 1;
            }
        }
    }

    return -1;
}
int lastOccuranceREC(vector<int> &arr, int l, int h, int target)
{

    if (l > h)
    {
        return -1;
    }
    int mid = l + (h - l) / 2;

    if (arr[mid] > target)
        return lastOccuranceREC(arr, l, mid - 1, target);
    else if (arr[mid] < target)
        return lastOccuranceREC(arr, mid + 1, h, target);
    else
    {
        if (mid == m - 1 || arr[mid + 1] != arr[mid])
            return mid;
        else
            return lastOccuranceREC(arr, mid + 1, h, target);
    }
}

int main()
{
    vector<int> arr = {1, 10, 10, 10, 20, 30, 40};
    int n = arr.size();
    m = n;
    int target = 10;
    cout << lastOccurance(arr, 0, n - 1, target);
    return 0;
}