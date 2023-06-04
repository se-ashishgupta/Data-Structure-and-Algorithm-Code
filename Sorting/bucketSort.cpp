#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(int arr[], int n, int k)
{
    int mx = arr[0];
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
    }
    mx++;
    vector<int> bkt[k];
    for (int i = 0; i < n; i++)
    {
        int bi = (k * arr[i]) / mx;
        bkt[bi].push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sort(bkt[i].begin(), bkt[i].end());
    }
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < bkt[i].size(); j++)
        {
            arr[index++] = bkt[i][j];
        }
    }
}

int main()
{
    int a[] = {30, 40, 10, 80, 5, 12, 70};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    bucketSort(a, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}