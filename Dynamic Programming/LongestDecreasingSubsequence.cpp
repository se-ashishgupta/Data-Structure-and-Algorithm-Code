#include <iostream>
#include <vector>
using namespace std;

int ldsTab(vector<int> arr) // Tc=O(n*n)  AS=O(n)
{
    int n = arr.size();
    vector<int> lis(n);

    lis[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        lis[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    int res = 1;
    for (int x : lis)
        res = max(res, x);

    return res;
}

int ceilIndex(vector<int> tail, int l, int r, int x)
{

    while (r > l)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= x)
            r = m;
        else
            l = m + 1;
    }
    return r;
}
int ldsBinarySearch(vector<int> arr) // Tc=O(nlogn)  AS=O(n)
{
    int n = arr.size();
    vector<int> tail(n);
    tail[0] = arr[n - 1];
    int length = 1;

    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] > tail[length - 1])
        {
            tail[length] = arr[i];
            length++;
        }
        else
        {
            int c = ceilIndex(tail, 0, length - 1, arr[i]);
            tail[c] = arr[i];
        }
    }
    return length;
}
int main()
{
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};

    cout << ldsTab(arr) << endl;

    cout << ldsBinarySearch(arr);
    return 0;
}
