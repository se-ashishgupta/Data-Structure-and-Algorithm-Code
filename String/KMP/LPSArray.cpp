#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
int longestpresuff(string str, int n) // O(n*n*n)
{
    for (int len = n - 1; len > 0; len--)
    {
        bool flag = true;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != str[n - len + i])
                flag = false;

            if (flag == true)
                return len;
        }
    }
    return 0;
}
void filllps(string str, int lps[])
{
    for (int i = 0; i < str.length(); i++)
    {
        lps[i] = longestpresuff(str, i + 1);
    }
}

int main()
{

    string str = "abbabb";
    int lps[str.size()];
    filllps(str, lps);
    for (int x : lps)
        cout << x << " ";

    return 0;
}