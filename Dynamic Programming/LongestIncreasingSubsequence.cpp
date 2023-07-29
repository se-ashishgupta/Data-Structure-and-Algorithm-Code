#include <iostream>
#include <vector>
using namespace std;

int lisTab(vector<int> arr) // Tc=O(n*n)  AS=O(n)
{
    int n = arr.size();
    vector<int> lis(n);

    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
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
int lisBinarySearch(vector<int> arr) // Tc=O(nlogn)  AS=O(n)
{
    int n = arr.size();
    vector<int> tail(n);
    tail[0] = arr[0];
    int length = 1;

    for (int i = 1; i < n; i++)
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
    vector<int> arr = {3, 10, 20, 4, 6, 7};

    cout << lisBinarySearch(arr);
    return 0;
}
