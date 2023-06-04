#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int CHAR = 256;
bool CheckForRotation(string &str, string &str1) // TC: O(n)   AS:O(n)
{
    if (str.length() != str1.length())
        return false;

    return ((str + str).find(str1) != string::npos);
    // find function return string::npos contsnt if string not found
}
bool CheckForRotationNaive(string &str, string &str1) // TC: O(n*n)   AS:O(1)
{
}

int main()
{

    string str = "abcd";
    string str1 = "cdab";
    cout << CheckForRotation(str, str1);

    return 0;
}