#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define d 256
// Iterative Solution
void RabinKarpAlgo(string &txt, string &ptr, int q) // TC: O(n+n1)   AS:O(1)
{
    int h = 1;
    int p = 0, t = 0;
    int txtSize = txt.size();
    int ptrSize = ptr.size();
    for (int i = 1; i < ptrSize; i++)
    {
        }

    for (int i = 0; i < ptrSize; i++)
    {
        p = (p * d + ptr[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    for (int i = 0; i <= txtSize - ptrSize; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < ptrSize; j++)
            {
                if (txt[i + j] != ptr[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < txtSize - ptrSize)
        {
            t = (d * (t - txt[i] * h) + txt[i + ptrSize]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}
int main()
{

    string txt = "GEEKS FOR GEEKS";
    string ptr = "GEEK";
    RabinKarpAlgo(txt, ptr, 101);
    return 0;
}