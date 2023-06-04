#include <iostream>
using namespace std;
void divisor(int n)
{
    int i, count = 0;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            count += i;
        }
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
        {
            if ((n / i) != i - 1)
            {
                cout << n / i << " ";
                count += (n / i);
            }
        }
    }
    cout << endl;
    cout << count;
}
int main()
{
    int n;
    cout << "enter number" << endl;
    cin >> n;
    divisor(n);
}