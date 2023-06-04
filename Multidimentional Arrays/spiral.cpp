#include <iostream>
using namespace std;
const int R = 3;
const int C = 4;
void rotateNaive(int arr[R][C]) // Q(R*C)
{
    int top = 0, left = 0, right = C - 1, bottom = R - 1;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
}
int main()
{
    int mat[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    rotateNaive(mat);

    return 0;
}
