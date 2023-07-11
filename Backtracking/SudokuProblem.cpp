#include <iostream>
#include <math.h>
using namespace std;
#define N 4

void printMatrix(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << sol[i][j] << " ";
        cout << endl;
    }
}
bool isSafe(int grid[N][N], int i, int j, int n)
{

    for (int k = 0; k < N; k++)
        if (grid[k][j] == n || grid[i][k] == n)
            return false;

    int s = sqrt(N);
    int rs = i - i % s;
    int cs = j - j % s;

    for (int a = 0; a < s; a++)
    {
        for (int b = 0; b < s; b++)
        {
            if (grid[a + rs][b + cs] == n)
                return false;
        }
    }

    return true;
}

bool solve(int grid[N][N])
{

    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (grid[i][j] == 0)
                break;

    if (i == N && j == N)
        return true;

    for (int n = 1; n <= N; n++)
    {
        if (isSafe(grid, i, j, n))
        {

            grid[i][j] = n;
            if (solve(grid))
                return true;
            grid[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int board[N][N] = {{1, 0, 3, 0},
                       {0, 0, 2, 1},
                       {0, 1, 0, 2},
                       {2, 4, 0, 0}};
    if (solve(board) == true)
    {
        printMatrix(board);
    }
    else
    {
        cout << "No" << endl;
    }

    return true;
}