#include <iostream>
using namespace std;
void unionsorted(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        else if (j > 0 && b[j] == b[j - 1])
        {
            j++;
            continue;
        }
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
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
    int a[] = {11, 15, 18, 20, 21};
    int b[] = {2, 11, 16, 19, 20, 21};
    int m = 5, n = 6;
    unionsorted(a, b, m, n);
}
