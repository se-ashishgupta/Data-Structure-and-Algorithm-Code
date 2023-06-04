#include <iostream>
using namespace std;
const int R = 4;
const int C = 4;
const int N = 4;

void rotateNaive(int arr[N][N])
{
    int temp[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[N - j - 1][i] = arr[i][j];
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

void rotate(int arr[N][N])
{

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        int low = 0, high = N - 1;
        while (low < high)
        {
            swap(arr[low][i], arr[high][i]);
            low++;
            high--;
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
    rotateNaive(mat);

    return 0;
}
