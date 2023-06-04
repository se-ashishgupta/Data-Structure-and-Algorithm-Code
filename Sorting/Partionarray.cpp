#include <iostream>
using namespace std;

// Naive Partition

// void partition(int arr[], int l, int h, int p)
// {
//     int temp[h - l + 1], index = 0;
//     for (int i = l; i <= h; i++)
//     {
//         if (arr[i] <= arr[p])
//         {
//             temp[index] = arr[i];
//             index++;
//         }
//     }
//     for (int i = l; i <= h; i++)
//     {
//         if (arr[i] > arr[p])
//         {
//             temp[index] = arr[i];
//             index++;
//         }
//     }
//     for (int i = 0; i <= h; i++)
//     {
//         cout << temp[i] << " ";
//     }
// }

// Lomuto Partition

// void lumotopartition(int arr[], int l, int h, int p)
// {
//     swap(arr[h], arr[p]);
//     int pivot = arr[h];
//     int i = l - 1;
//     for (int j = l; j <= h - 1; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[h]);
// }

// Hoare's Partition

void hoarespartition(int arr[], int l, int h)
{

    int pivot = arr[l], i = l - 1, j = h + 1;

    while (true)
    {
        do
        {
            i++;

        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            break;
        }

        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p = 6;
    hoarespartition(arr, 0, n - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}