#include <iostream>
using namespace std;
#define N 4
bool isSafe(int maze[N][N], int i, int j)
{
    return (i < N && j < N && maze[i][j] == 1);
}
void printMatrix(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << sol[i][j] << " ";
        cout << endl;
    }
}

bool solveMazeRec(int maze[N][N], int sol[N][N], int i, int j)
{
    if (i == N - 1 && j == N - 1)
    {
        sol[i][j] = 1;
        return true;
    }
    if (isSafe(maze, i, j) == true)
    {
        sol[i][j] = 1;
        if (solveMazeRec(maze, sol, i + 1, j) == true)
            return true;
        else if (solveMazeRec(maze, sol, i, j + 1) == true)
            return true;
        sol[i][j] = 0;
    }
    return false;
}

bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    if (solveMazeRec(maze, sol, 0, 0) == false)
        return false;

    printMatrix(sol);
    return true;
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};
    solveMaze(maze);
    return true;
}