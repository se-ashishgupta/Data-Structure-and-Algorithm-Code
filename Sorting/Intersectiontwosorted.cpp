#include <iostream>
using namespace std;
// void intersection(int a[], int b[], int m, int n)
// {
//     for (int i = 0; i < m; i++)
//     {
//         if (i > 0 && a[i] == a[i - 1])
//             continue;
//         for (int j = 0; j < n; j++)
//         {
//             if (a[i] == b[j])
//             {
//                 cout << a[i] << " ";
//                 break;
//             }
//         }
//     }
// }
void intersection(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int a[] = {2, 20, 20, 20, 40, 60};
    int b[] = {1, 20, 20, 40, 60};
    int m = 6, n = 5;
    intersection(a, b, m, n);
    return 0;
}