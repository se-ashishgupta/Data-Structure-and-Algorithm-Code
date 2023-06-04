#include <iostream>
using namespace std;
int hcf1(int a, int b)
{
    int m = min(a, b);
    while (m > 0)
    {
        if (a % m == 0 && b % m == 0)
            return m;

        m--;
    }
}

int hcf2(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
            b = b - a;
    }

    return a;
}

int hcf3(int a, int b)
{
    if (b == 0)
        return a;
    else
        return hcf3(b, a % b);
}
int main()
{
    int n1, n2;
    cout << "enter number";
    cin >> n1 >> n2;
    cout << hcf3(n1, n2);
    return 0;
}