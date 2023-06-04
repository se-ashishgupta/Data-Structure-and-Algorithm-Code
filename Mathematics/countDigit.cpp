#include <iostream>
using namespace std;

int evenlyDivides(int n)
{
    // code here
    int count = 0;
    int n1 = n;
    while (n1 > 0)
    {
        int f = n1 % 10;
        if (n % f == 0)
        {
            count++;
        }
        n1 = n1 / 10;
    }
    return count;
}

int main()
{
    int n = 2446;
    cout << evenlyDivides(n);
    return 0;
}