#include <iostream>
using namespace std;
// int coutinversiob(int a[], int n)
// {
//     int count = 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (a[i] > a[j])
//                 count++;
//         }
//     }
//     return count;
// }
int coutinversiob(int a[], int l, int m, int h)
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

    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
            k++;
        }
        else
        {
            a[k] = right[j];
            j++;
            k++;
            res = res + (n1 - i);
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

    return res;
}

int main()
{
    int a[] = {2, 5, 8, 11, 3, 6, 9, 13};
    int n = sizeof(a) / sizeof(a[0]);
    int h = n - 1;
    int l = 0, m = l + (h - l) / 2;
    cout << coutinversiob(a, l, m, h);
}