#include <iostream>
using namespace std;
int trailling(int n)
{
    int count = 0;
    for (int i = 5; i <= n; i = i * 5)
    {
        count = count + n / i;
        }
    return count;
}
int main()
{
    int n;
    cout << "enter number";
    cin >> n;
    cout << trailling(n);
}