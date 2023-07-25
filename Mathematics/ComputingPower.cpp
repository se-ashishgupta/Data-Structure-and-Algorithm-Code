#include <iostream>
using namespace std;

// int power(int x, int n)
// {

//     int res = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         res = res * x;
//     }
//     return res;
// }

// int power(int x, int n)
// {

//     if (n == 0)
//         return 1;
//     int temp = power(x, n / 2);
//     temp = temp * temp;
//     if (n % 2 == 0)
//         return temp;
//     else
//         return temp * x;
// }

int power(int x, int n)
{

    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power(x * x, n / 2);
    else

        return x * power(x * x, (n - 1) / 2);
}

int main()
{
    cout << power(2, 5);
    return 0;
}
