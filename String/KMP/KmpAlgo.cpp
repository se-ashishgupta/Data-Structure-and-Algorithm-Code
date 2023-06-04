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
void kmp(string txt, string ptr) // O(2n) n is the length of text
{
    int txtSize = txt.length();
    int ptrSize = ptr.length();
    int lps[ptrSize];
    filllps(ptr, lps);
    int i = 0, j = 0;
    while (i < txtSize)
    {
        if (ptr[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == ptrSize)
        {
            cout << "Pattern Found at Index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < txtSize && ptr[j] != txt[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{

    string txt = "abbabb";
    string ptr = "bb";
    kmp(txt, ptr);

    return 0;
}