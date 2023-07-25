#include <iostream>
#include <vector>
using namespace std;

int fibo(int n, vector<int> memo)
{
    if (memo[n] == -1)
    {
        int res;
        if (n == 0 || n == 1)
            return n;
        else
            res = fibo(n - 1, memo) + fibo(n - 2, memo);

        memo[n] = res;
    }
    return memo[n];
}
int main()
{
    int n = 5;
    vector<int> memo(n + 1, -1);
    cout << fibo(n, memo);
    return 0;
}
