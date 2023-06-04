#include <iostream>
using namespace std;
int main()
{
    int L = 22, R = 111;
    int res = 0, m = 0;
    if (L > 0 && L <= 10)
    {
        res += 10 - L;
    }
    else if (L >= 11)
    {
        m = L / 11;
    }
    cout << m;
    res += (R / 11) - m + 1;
    cout << res;
}
