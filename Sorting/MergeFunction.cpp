#include <iostream>
using namespace std;
// void mergefun(int a[], int l, int m, int h)
// {
//     int n1 = m - l + 1, n2 = h - m;
//     int left[n1], right[n2];
//     for (int p = 0; p < n1; p++)
//         left[p] = a[l + p];
//     for (int p = 0; p < n2; p++)
//         right[p] = a[m + 1 + p];
//     int i = 0, j = 0, k = 0;
//     while (i < n1 && j < n2)
//     {
//         if (left[i] <= right[j])
//         {
//             a[k] = left[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             a[k] = right[j];
//             j++;
//             k++;
//         }
//     }
//     while (i < n1)
//     {
//         a[k] = left[i];
//         i++;
//         k++;
//     }
//     while (j < n2)
//     {
//         a[k] = right[j];
//         j++;
//         k++;
//     }
// }

void mergefun(int a[], int l, int m, int h)
{
    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = a[m + 1 + i];
    }

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
            k++;
        }
        else if (left[i] > right[j])
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}
int main()
{
    int a[] = {10, 15, 20, 30, 40, 45, 11, 12, 13, 50, 60, 90};
    int n = sizeof(a) / sizeof(a[0]), l = 0, h = n - 1, m = 5;
    mergefun(a, l, m, h);
    for (int i = 0; i < h + 1; i++)
        cout << a[i] << " ";
}