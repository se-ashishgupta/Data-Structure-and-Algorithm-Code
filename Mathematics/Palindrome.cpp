#include <iostream>
using namespace std;
bool palindrome(int n)
{
    int rev = 0, temp = n;
    while (temp != 0)
    {
        int rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }

    return (rev == n);
}
int main()
{
    int n;
    cout << "enter number";
    cin >> n;
    cout << palindrome(n);
    return 0;
}