#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
void Morethannbykoccurence(int arr[], int n, int k) // O(n)    AS:O(n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int r = n / k;
    for (auto x : freq)
    {
        if (x.second > r)
            cout << x.first << " ";
    }
}

void MorethannbykoccurenceNaive(int arr[], int n, int k) // O(nlogn)
{
    sort(arr, arr + n);
    int i = 1, count = 1;
    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            count++;
            i++;
        }

        if (count > n / k)
            cout << arr[i - 1] << " ";

        count = 1;
        i++;
    }
}

int main()
{
    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    MorethannbykoccurenceNaive(arr, size, k);
    return 0;
}