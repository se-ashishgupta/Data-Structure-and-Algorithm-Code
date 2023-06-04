#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int CHAR = 256;
bool CheckForAnagram(string &str, string &str1, int i)
{
    int size1 = str.length();
    int size2 = str1.length();
    int count[CHAR] = {0};
    for (int j = 0; j < size2; j++)
    {
        count[str[i + j]]--;
        count[str1[j]]++;
    }
    for (int j = 0; j < CHAR; j++)
    {
        if (count[j] != 0)
            return false;
    }
    return true;
}
bool AnagramSearchNaive(string &str, string &str1)
{

    int size1 = str.length();
    int size2 = str1.length();
    for (int i = 0; i <= size1 - size2; i++)
    {
        if (CheckForAnagram(str, str1, i))
            return true;
    }
    return false;
}

// Efficient
bool areSame(int CT[], int CP[])
{
    for (int i = 0; i < CHAR; i++)
    {
        if (CT[i] != CP[i])
            return false;
    }
    return true;
}
bool AnagramSearch(string &str, string &str1) // TC: O(n+(n-m)*CHAR) ===O(n*CHAR)   SC: O(CHAR)
{

    int size1 = str.length();
    int size2 = str1.length();
    int CT[CHAR] = {0}, CP[CHAR] = {0};
    for (int i = 0; i < size2; i++)
    {
        CT[str[i]]++;
        CP[str1[i]]++;
    }
    for (int i = size2; i < size1; i++)
    {
        if (areSame(CT, CP))
            return true;
        CT[str[i]]++;
        CT[str[i - size2]]--;
    }
    return false;
}

int main()
{

    string str = "geeksforgeeks";
    string str1 = "frog";
    cout << AnagramSearch(str, str1);

    return 0;
}