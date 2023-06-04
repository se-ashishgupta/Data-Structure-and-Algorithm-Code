#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool palindrome(string str) // TC: O(n)in worst case   O(1) in best case    AS:O(1)
{
    // int size = str.length(), i = 0;
    // while (i < size / 2)
    // {
    //     if (str[i] == str[size - 1 - i])
    //         i++;
    //     else
    //         return false;
    // }

    int begin = 0, end = str.length() - 1;
    while (begin < end)
    {
        if (str[begin] != str[end])
            return false;
        begin++;
        end--;
    }
    return true;
}
bool palindromeNaive(string &str) // TC: O(n)   AS:O(n)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return (rev == str);
}
int main()
{

    string str = "aba";
    cout << palindromeNaive(str);
    return 0;
}