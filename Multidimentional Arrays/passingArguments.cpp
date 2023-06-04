#include <iostream>
#include <vector>
using namespace std;
// Using basic//
// void print(int mat[][2], int m)
// {
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             cout << mat[i][j] << " ";
//         }
//     }
// }

// Using Double Pointer//
// void print(int **arr, int m, int n)
// {
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//     }
// }

// Using Array of Pointer//
// void print(int *arr[], int m, int n)
// {
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//     }
// }

// Using Array of Vector//
// void print(vector<int> arr[], int m, int n)
// {
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//     }
// }

// Using Vector of Vectors//
void print(vector<vector<int>> arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}
int main()
{

    // Using basic//
    //  int mat[3][2] = {
    //      {10, 20},
    //      {30, 40},
    //      {50, 60}};
    //  print(mat, 3);

    // Using Double Pointer//
    // int m = 3, n = 2;
    // int **arr;
    // arr = new int *[m];
    // for (int i = 0; i < m; i++)
    // {
    //     arr[i] = new int[n];
    //     for (int j = 0; j < n; j++)
    //     {
    //         arr[i][j] = i;
    //     }
    // }
    // print(arr, m, n);

    // Using Array of Pointer//
    // int m = 3, n = 2;
    // int *arr[m];
    // for (int i = 0; i < m; i++)
    // {
    //     arr[i] = new int[n];
    //     for (int j = 0; j < n; j++)
    //     {
    //         arr[i][j] = i;
    //     }
    // }
    // print(arr, m, n);

    // Using Array of Vector//
    // int m = 3, n = 2;
    // vector<int> arr[m];
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         arr[i].push_back(i);
    //     }
    // }
    // print(arr, m, n);

    // Using Vector of Vectors//
    int m = 3, n = 2;
    vector<vector<int>> arr;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(i);
        }

        arr.push_back(v);
    }
    print(arr, m, n);

    return 0;
}