#include <iostream>
using namespace std;

// int factorial(int n)
// {
//     int f = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         f = f * i;
//     }
//     return f;
// }

int factorial(int n)
{
    if (n == 0)
    {
        /* code */
        return 1;
    }
    else
        return n * factorial(n - 1);
}

int main()
{
    int n = 12;
    cout << factorial(n);
}