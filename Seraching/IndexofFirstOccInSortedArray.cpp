#include <iostream>
#include <vector>
using namespace std;

int firstOccurance(vector<int> &arr, int l, int h, int target)
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

            if (mid == 0 || arr[mid - 1] != arr[mid])
            {
                return mid;
            }
            else
            {
                h = mid - 1;
            }
        }
    }

    return -1;
}
int firstOccuranceREC(vector<int> &arr, int l, int h, int target)
{

    if (l > h)
    {
        return -1;
    }
    int mid = l + (h - l) / 2;

    if (arr[mid] > target)
        return firstOccuranceREC(arr, l, mid - 1, target);
    else if (arr[mid] < target)
        return firstOccuranceREC(arr, mid + 1, h, target);
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;
        else
            return firstOccuranceREC(arr, l, mid - 1, target);
    }
}

int main()
{
    vector<int> arr = {1, 10, 10, 10, 20, 30, 40};
    int n = arr.size();
    int target = 20;
    cout << firstOccuranceREC(arr, 0, n - 1, target);
    return 0;
}