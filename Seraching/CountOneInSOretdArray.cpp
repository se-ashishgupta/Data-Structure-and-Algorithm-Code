#include <iostream>
#include <vector>
using namespace std;
int m;
int binarySeacrh(vector<int> &arr, int l, int h)
{

    while (l <= h)
    {

        int mid = l + (h - l) / 2;

        if (arr[mid] == 0)
        {
            l = mid + 1;
        }
        else
        {
            if (mid == 0 || arr[mid - 1] == 0)
                return m - mid;
            else
                h = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = arr.size();
    m = n;
    int target = 10;
    // int res = firstOccurance(arr, 0, n - 1, target);
    // if (res == -1)
    //     cout << -1;
    // else
    //     cout << lastOccurance(arr, 0, n - 1, target) - res + 1;
    cout << binarySeacrh(arr, 0, n - 1);
    return 0;
}