#include <iostream>
using namespace std;
const int R = 4;
const int C = 4;
const int N = 4;

// Efficient Solution   1)In place 2)One Traversal
void transpose(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            swap(arr[i][j], arr[j][i]); /* code */
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}

void transposeNaive(int arr[N][N])
{
    int temp[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[i][j] = arr[j][i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}

int main()
{
    int mat[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    transposeNaive(mat);

    return 0;
}