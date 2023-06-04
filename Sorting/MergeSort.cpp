#include <iostream>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int p = 0; p < n1; p++)
        left[p] = a[l + p];

    for (int p = 0; p < n2; p++)
        right[p] = a[m + 1 + p];

    int i = 0, j = 0, k = l;
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

void mergesort(int arr[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int a[] = {10, 15, 20, 11, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]), l = 0, r = n - 1;
    mergesort(a, l, r);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}