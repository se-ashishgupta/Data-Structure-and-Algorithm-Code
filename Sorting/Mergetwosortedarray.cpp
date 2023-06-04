#include <iostream>
using namespace std;
// void mtsa(int a[], int b[], int m, int n)
// {
//     int i = 0, j = 0, k = 0, res[m + n];
//     while (i < m && j < n)
//     {
//         if (a[i] <= b[j])
//         {
//             res[k] = a[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             res[k] = b[j];
//             j++;
//             k++;
//         }
//     }
//     while (i < m)
//     {
//         res[k] = a[i];
//         i++;
//         k++;
//     }
//     while (j < n)
//     {
//         res[k] = b[j];
//         j++;
//         k++;
//     }
//     for (int x : res)
//         cout << x << " ";
// }

void mtsa(int a[], int b[], int m, int n)
{

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < m)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < n)
    {
        cout << b[j] << " ";
        j++;
    }
}

int main()
{
    int a[] = {11, 15, 18, 20, 21};
    int b[] = {2, 13, 16, 19, 22, 25};
    int m = 5, n = 6;
    mtsa(a, b, m, n);
}