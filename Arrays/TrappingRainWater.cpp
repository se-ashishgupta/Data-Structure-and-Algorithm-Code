#include <iostream>
#include <vector>
using namespace std;

int trappingRainNaive(vector<int> &arr, int n)
{
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int lmax = arr[i];
        for (int j = 0; j < i; j++)
        {
            lmax = max(arr[j], lmax);
        }
        int rmax = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            rmax = max(arr[j], rmax);
        }

        res += min(lmax, rmax) - arr[i];
    }

    return res;
}
int trappingRain(vector<int> &arr, int n)
{
    vector<int> lmax(n);
    vector<int> rmax(n);

    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(arr[i], lmax[i - 1]);
    }

    rmax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        rmax[i] = max(arr[i], rmax[i - 1]);
    }

    int profit = 0;
    for (int i = 1; i < n - 1; i++)
    {
        profit += min(lmax[i], rmax[i]) - arr[i];
    }

    return profit;
}
int main()
{
    vector<int> arr = {3, 0, 1, 2, 5};
    int n = arr.size();
    cout << trappingRainNaive(arr, n);
    return 0;
}