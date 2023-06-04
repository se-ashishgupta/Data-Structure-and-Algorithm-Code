#include <iostream>
using namespace std;
#include <algorithm>

// Efficient Approch

// int partition(int arr[], int l, int r)
// {
//     int pivot = arr[r], i = l - 1;
//     for (int j = l; j <= r - 1; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[j], arr[i]);
//         }
//     }
//     swap(arr[r], arr[i + 1]);
//     return (i + 1);
// }
// int kthsmallest(int arr[], int n, int k)
// {
//     int l = 0, r = n - 1;
//     while (l <= r)
//     {
//         int p = partition(arr, l, r);
//         if (p == k - 1)
//             return arr[p];
//         else if (p > k - 1)
//             r = p - 1;
//         else
//             l = p + 1;
//     }
//     return -1;
// }

// Naive Approch

int kthsmallest(int arr[], int n, int k)
{

    sort(arr, arr + n);
    return arr[k - 1];
}

int main()
{
    int arr[] = {5, 3, 8, 10, 4, 2, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 1;
    cout << kthsmallest(arr, n, k) << endl;
    return 0;
}