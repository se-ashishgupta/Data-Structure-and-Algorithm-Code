#include <iostream>
using namespace std;

int hcf(int n1, int n2)
{

    while (n1 != n2)
    {
        if (n2 == 0)
            return n1;
        else
            return hcf(n2, n1 % n2);
    }
    return n1;
}
int lcm(int n1, int n2)
{
    return (n1 * n2) / hcf(n1, n2);
}

int main()
{
    int n1, n2;
    cout << "enter number";
    cin >> n1 >> n2;
    cout << lcm(n1, n2);
    return 0;
}