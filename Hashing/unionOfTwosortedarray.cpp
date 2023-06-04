#include <iostream>
#include <unordered_set>
using namespace std;
int Union(int arr[], int n, int arr1[], int m) // TC: O(n+m)  SC: O(n+m)
{
    unordered_set<int> set;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }
    for (int j = 0; j < m; j++)
    {

        set.insert(arr1[j]);
    }
    return set.size();
}

int UnionNaive(int arr[], int n, int arr1[], int m) // O((m+n)*(m+n))    AS:O(m+n)
{
    int res = 0;
    int temp[m + n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    for (int j = 0; j < m; j++)
        temp[n + j] = arr1[j];

    for (int i = 0; i < m + n; i++)
    {
        int flag = false;
        for (int j = 0; j < i; j++)
        {
            if (temp[i] == temp[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            res++;
    }
    return res;
}
int main()
{
    int arr[] = {15, 20, 5, 15};
    int arr1[] = {15, 15, 15, 20, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << Union(arr, size, arr1, size1);
    return 0;
}