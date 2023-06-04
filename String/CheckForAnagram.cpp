#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int CHAR = 256;
bool CheckForAnagram(string &str, string &str1) // TC: O(n+256)   AS:O(1)
{
    int size1 = str.length();
    int size2 = str1.length();
    if (size1 != size2)
        return false;
    int count[CHAR] = {0};
    for (int i = 0; i < size1; i++)
    {
        count[str[i]]++;
        count[str1[i]]--;
    }
    for (int i = 0; i < CHAR; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}
bool CheckForAnagramNaive(string &str, string &str1) // TC: O(nlogn)   AS:O(1)
{

    int size1 = str.length();
    int size2 = str1.length();
    if (size1 != size2)
        return false;
    sort(str.begin(), str.end());
    sort(str1.begin(), str1.end());
    if (str == str1)
        return true;
    else
        return false;
}

int main()
{

    string str = "bc";
    string str1 = "ad";
    cout << CheckForAnagram(str, str1);

    return 0;
}