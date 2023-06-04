#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#define R 4
#define C 5
using namespace std;
int getMaxArea(int arr[], int n) // TC: O(n) One Traversal and one stack
{

    stack<int> s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }
    while (s.empty() == false)
    {
        int tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }
    return res;
}

int maxRectangle(int mat[R][C])
{
    int res = getMaxArea(mat[0], C);
    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 1)
            {
                mat[i][j] += mat[i - 1][j];
            }
        }
        res = max(res, getMaxArea(mat[i], C));
    }
    return res;
}
int main()
{
    int arr[R][C] = {{1, 0, 0, 1, 1}, {0, 0, 0, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 1, 1, 1}};
    cout << maxRectangle(arr);
    return 0;
}