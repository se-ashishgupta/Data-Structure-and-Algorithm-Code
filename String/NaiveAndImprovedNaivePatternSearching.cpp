#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int CHAR = 256;
void NaivePatternSearching(string &txt, string &pat) // TC: O((txtSize - patSize+1)*patSize)   AS:O(1)
{
    int txtSize = txt.length();
    int patSize = pat.length();
    for (int i = 0; i <= txtSize - patSize; i++)
    {
        int j;
        for (j = 0; j < patSize; j++)
        {
            if (pat[j] != txt[i + j])
                break;
        }
        if (j == patSize)
            cout << i << " ";
    }
}
void NaivePatternSearchingImproved(string &txt, string &pat) // TC: O(txtSize)   AS:O(1)
{
    int txtSize = txt.length();
    int patSize = pat.length();
    for (int i = 0; i <= txtSize - patSize;)
    {
        int j;
        for (j = 0; j < patSize; j++)
        {
            if (pat[j] != txt[i + j])
                break;
        }
        if (j == patSize)
            cout << i << " ";

        if (j == 0)
            i++;
        else
            i = i + j;
    }
}

int main()
{

    string txt = "GEEKSFORGEEKS";
    string pat = "EKS";
    NaivePatternSearchingImproved(txt, pat);

    return 0;
}