#include <iostream>
#include <unordered_set>
using namespace std;
int intersection(int arr[], int n, int arr1[], int m) // TC: O(n+m)  SC: O(n)
{
    unordered_set<int> set;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }
    for (int j = 0; j < m; j++)
    {
        if (set.find(arr1[j]) != set.end())
        {
            res++;
            set.erase(arr1[j]);
        }
    }
    return res;
}

int intersectionNaive(int arr[], int n, int arr1[], int m) // O(m*(m+n))
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;

        for (int j = 0; j < m; j++)
        {
            if (arr[i] == arr1[j])
            {
                res++;
                break;
            }
        }
    }
    return res;
}
int main()
{
    int arr[] = {10, 15, 20, 15, 30, 30, 5};
    int arr1[] = {30, 5, 30, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << intersection(arr, size, arr1, size1);
    return 0;
}