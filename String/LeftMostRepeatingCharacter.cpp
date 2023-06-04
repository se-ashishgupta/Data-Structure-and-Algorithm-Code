#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int CHAR = 256;
int LeftMostRepeatingCharacter(string &str) // TC: O(n)   AS:O(1)     Two Traversal
{
    int size = str.length();
    int count[CHAR] = {0};
    for (int i = 0; i < size; i++)
    {
        count[str[i]]++;
    }
    for (int i = 0; i < size; i++)
    {
        if (count[str[i]] > 1)
            return i;
    }
    return -1;
}
int LeftMostRepeatingCharacter1(string &str) // TC: O(n+CHAR)   AS:O(1)   One Traversal Solution 1
{
    int size = str.length();
    int fIndex[CHAR] = {0};
    fill(fIndex, fIndex + CHAR, -1);
    int res = INT16_MAX;
    for (int i = 0; i < size; i++)
    {
        int fi = fIndex[str[i]];
        if (fi == -1)
            fIndex[str[i]] = i;
        else
            res = min(res, fi);
    }

    return (res == INT16_MAX) ? -1 : res;
}
int LeftMostRepeatingCharacter2(string &str) // TC: O(n+CHAR)   AS:O(1)   One Traversal Solution 2
{
    int size = str.length();
    bool visited[CHAR] = {false};
    // fill(visited, visited + CHAR, false);
    int res = -1;
    for (int i = size - 1; i >= 0; i--)
    {

        if (visited[str[i]])
            res = i;
        else
            visited[str[i]] = true;
    }

    return res;
}
int LeftMostRepeatingCharacterNaive(string &str) // TC: O(n*n)   AS:O(1)
{
    int size = str.length();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (str[i] == str[j])
                return i;
        }
    }
    return -1;
}

int main()
{

    string str = "ab";
    cout << LeftMostRepeatingCharacter2(str);

    return 0;
}