#include <iostream>
using namespace std;

int squareRoot(int n, int l, int h)
{

    int ans = -1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        int msq = mid * mid;

        if (msq == n)
        {
            return mid;
        }

        if (msq > n)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
            ans = mid;
        }
    }

    return ans;
}
int main()
{
    int n = 15;
    cout << squareRoot(n, 1, n);
    return 0;
}