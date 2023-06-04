#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int CHAR = 256;
int LeftMostNonRepeatingCharacter(string &str) // TC: O(n)   AS:O(CHAR)     Two Traversal
{
    int freq[CHAR] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (freq[str[i]] == 1)
            return i;
    }
    return -1;
}
int LeftMostNonRepeatingCharacter1(string &str) // TC: O(n+CHAR)   AS:O(CHAR)   One Traversal Solution 1
{
    int fi[CHAR];
    fill(fi, fi + CHAR, -1);
    int res = INT16_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        if (fi[str[i]] == -1)
            fi[str[i]] = i;
        else
            fi[str[i]] = -2;
    }
    for (int i = 0; i < CHAR; i++)
    {
        if (fi[i] >= 0)
            res = min(res, fi[i]);
    }
    return (res == INT16_MAX) ? -1 : res;
}
int LeftMostNonRepeatingCharacterNaive(string &str) // TC: O(n*n)   AS:O(1)
{
    for (int i = 0; i < str.length(); i++)
    {
        bool flag = false;
        for (int j = 0; j < str.length(); j++)
        {
            if (i != j && str[i] == str[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return i;
    }
    return -1;
}

int main()
{

    // string str = "abcabc";
    string str = "apple";
    cout << LeftMostNonRepeatingCharacter1(str);

    return 0;
}