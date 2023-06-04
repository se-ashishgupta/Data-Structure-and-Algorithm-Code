#include <iostream>
using namespace std;

// void countSort(int arr[], int n, int k)
// {
//     int count[k];
//     for (int i = 0; i < k; i++)
//         count[i] = 0;
//     for (int i = 0; i < n; i++)
//         count[arr[i]]++;
//     for (int i = 1; i < k; i++)
//         count[i] = count[i - 1] + count[i];
//     int output[n];
//     for (int i = n - 1; i >= 0; i--)
//     {
//         output[count[arr[i]] - 1] = arr[i];
//         count[arr[i]]--;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = output[i];
//     }
// }

void countSort(int arr[], int n, int k)
{
    int count[k];
    for (int i = 0; i < k; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            arr[index] = i;
            index++;
        }
    }
}
int main()
{
    int a[] = {1, 4, 4, 1, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    countSort(a, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}