#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

void filllps(string str, int lps[]) // O(n) n is length of pattern
{
    int n = str.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

int main()
{

    string txt = "abbabb";
    int lps[txt.size()];
    filllps(txt, lps);
    for (int x : lps)
        cout << x << " ";

    return 0;
};