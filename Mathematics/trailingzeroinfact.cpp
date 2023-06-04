#include <iostream>
#include <iostream>
using namespace std;

int trailingZero(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i = i * 5)
    {
        /* code */
        res = res + n / i;
    }

    return res;
}

int main()
{
    int n = 12;
    cout << trailingZero(n);
    return 0;
}