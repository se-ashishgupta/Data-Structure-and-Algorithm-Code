#include <iostream>
using namespace std;
const int R = 4;
const int C = 4;
const int N = 4;
void searchNaive(int arr[R][C], int x)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == x)
            {
                cout << "Found at (" << i << " " << j << ")";
                return;
            }
        }
    }
    cout << "Not Found";
}
void search(int arr[R][C], int x) // Q(R*C)
{
    int i = 0, j = C - 1;
    while (i < R && j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << "Found at (" << i << " " << j << ")";
            return;
        }
        else if (arr[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout << "Not Found";
}
int main()
{
    int mat[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int x = 16;

    searchNaive(mat, x);

    return 0;
}
