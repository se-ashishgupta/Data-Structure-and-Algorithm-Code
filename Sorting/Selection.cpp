#include <iostream>
using namespace std;
// void selection(int arr[], int n)
// {
//     int temp[n];
//     for (int i = 0; i < n; i++)
//     {
//         int mi = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] < arr[mi])
//             {
//                 mi = j;
//             }
//         }
//         temp[i] = arr[mi];
//         arr[mi] = INT16_MAX;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = temp[i];
//     }
// }

void selection(int arr[], int n)
{
    int mi;
    for (int i = 0; i < n - 1; i++)
    {
        mi = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[mi])
                mi = j;

        swap(arr[mi], arr[i]);
    }
}
int main()
{

    int arr[] = {4, 5, 6, 12, 2, 1, 45, 9};
    int n = 8;
    selection(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}