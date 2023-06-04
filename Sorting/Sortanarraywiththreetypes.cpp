#include <iostream>
#include <algorithm>
using namespace std;

// void sortarraytwotypes(int arr[], int n)
// {
//     int temp[n], index = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             temp[index] = arr[i];
//             index++;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 1)
//         {
//             temp[index] = arr[i];
//             index++;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 2)
//         {
//             temp[index] = arr[i];
//             index++;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = temp[i];
//     }
// }

void sortarraytwotypes(int arr[], int n)
{
    int l = 0, m = 0, h = n - 1;
    while (m <= h)
    {
        if (arr[m] == 0)
        {
            swap(arr[l], arr[m]);
            l++;
            m++;
        }
        else if (arr[m] == 1)
        {
            m++;
        }
        else
        {
            swap(arr[m], arr[h]);
            h--;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 2, 1, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortarraytwotypes(arr, n);
    for (int x : arr)
        cout << x << " ";

    return 0;
}