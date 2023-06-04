#include <iostream>
using namespace std;

void cyclesort(int arr[], int n)
{
    for (int cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for (int i = cs + 1; i < n; i++)
        {
            if (arr[i] < item)
                pos++;
        }
        swap(item, arr[pos]);
        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; i++)
            {
                if (arr[i] < item)
                    pos++;
            }
            swap(item, arr[pos]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int a[] = {20, 40, 50, 10, 30};
    int n = sizeof(a) / sizeof(a[0]);

    cyclesort(a, n);
    return 0;
}