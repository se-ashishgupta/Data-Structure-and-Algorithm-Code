#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
// Iterative Solution
bool CheckStringSubsequence(string &str, string &str1) // TC: O(n+n1)   AS:O(1)
{
    int i = 0, j = 0;
    while (i < str.length() && j < str1.length())
    {
        if (str[i] == str1[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    if (j == str1.length())
        return true;
    else
        return false;
}
// Recursive Solution
bool CheckStringSubsequenceRecursive(string &str, string &str1, int n, int n1) // TC: O(n+n1)   AS:O(n+n1)
{
    if (n1 == 0)
        return true;
    if (n == 0)
        return false;

    if (str[n - 1] == str1[n1 - 1])
        return CheckStringSubsequenceRecursive(str, str1, n - 1, n1 - 1);
    else
        return CheckStringSubsequenceRecursive(str, str1, n - 1, n1);
}

int main()
{

    string str = "GEEKSFORGEEKS";
    string str1 = "GRGES";
    // cout << CheckStringSubsequence(str, str1);
    cout << CheckStringSubsequenceRecursive(str, str1, str.length(), str1.length());
    return 0;
}