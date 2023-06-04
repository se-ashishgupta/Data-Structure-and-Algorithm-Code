#include <iostream>
#include <unordered_set>
using namespace std;
int count(int arr[], int n)
{
    // unordered_set<int> set;
    // for (int i = 0; i < n; i++)
    // {
    //     set.insert(arr[i]);
    // }
    unordered_set<int> set(arr, arr + n);
    return set.size();
}

int countNaive(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
                flag = false;
            break;
        }
        if (flag == true)
        {
            res++;
        }
    }
    return res;
}
int main()
{
    int arr[] = {10, 11, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << count(arr, size);
    return 0;
}