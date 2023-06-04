#include <iostream>
#include <algorithm>
using namespace std;

// void sortarraytwotypes(int arr[], int n)
// {
//     int i = -1, j = n;
//     while (true)
//     {
//         do
//         {
//             i++;
//         } while (arr[i] < 0);
//         do
//         {
//             j--;
//         } while (arr[j] >= 0);
//         if (i >= j)
//             return;
//         swap(arr[i], arr[j]);
//     }
// }

void sortarraytwotypes(int arr[], int n)
{
    int temp[n], index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp[index] = arr[i];
            index++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp[index] = arr[i];
            index++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int arr[] = {-12, 18, -10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortarraytwotypes(arr, n);
    for (int x : arr)
        cout << x << " ";

    return 0;
}