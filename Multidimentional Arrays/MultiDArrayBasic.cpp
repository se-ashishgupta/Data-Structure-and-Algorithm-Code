#include <iostream>
#include <vector>
using namespace std;

int main()
{

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
    //         cout << arr[i][j] << " ";
    //     }
    // }

    // Using Array of Pointer//
    // int m = 3, n = 2;
    // int *arr[m];
    // for (int i = 0; i < m; i++)
    // {
    //     arr[i] = new int[n];
    //     for (int j = 0; j < n; j++)
    //     {
    //         arr[i][j] = i;
    //         cout << arr[i][j] << " ";
    //     }
    // }

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
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    // }

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
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
    }

    return 0;
}