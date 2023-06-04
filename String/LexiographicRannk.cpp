#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int CHAR = 256;

int fact(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}
int LexiographicRannk(string &str) // TC: O(n*n)   AS:O(1)
{
    int size = str.length();
    int res = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int countSmaller = 0;
        for (int j = i + 1; j < size; j++)
        {
            if (str[j] < str[i])
                countSmaller++;
        }
        res = res + countSmaller * fact(size - 1 - i);
    }
    return res + 1;
}
int LexiographicRannk1(string &str) // TC: O(CHAR + n + CHAR + n*CHAR) == O(n*CHAR) AS:O(1)
{
    int size = str.length();
    int res = 1;
    int mul = fact(size);
    int count[CHAR] = {0};
    for (int i = 0; i < size; i++)
        count[str[i]]++;
    for (int i = 1; i < CHAR; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < size - 1; i++)
    {
        mul = mul / (size - i);
        res = res + count[str[i] - 1] * mul;
        for (int j = str[i]; j < CHAR; j++)
            count[j]--;
    }
    return res;
}
bool LexiographicRannkNaive(string &str, string &str1) // TC: O(nlogn)   AS:O(1)
{
}

int main()
{

    string str = "STRING";
    cout << LexiographicRannk1(str);

    return 0;
}