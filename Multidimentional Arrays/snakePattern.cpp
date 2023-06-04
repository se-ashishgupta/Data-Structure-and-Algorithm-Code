#include <iostream>
using namespace std;
const int R = 4;
const int C = 4;

void printSnake(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {

        if (i % 2 == 0)
        {
            for (int j = 0; j < C; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int j = C - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}

int main()
{
    int mat[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    // for (int i = 0; i < 4; i = i + 2)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     for (int j = 3; j >= 0; j--)
    //     {
    //         cout << mat[i + 1][j] << " ";
    //     }
    // }

    printSnake(mat);

    return 0;
}
