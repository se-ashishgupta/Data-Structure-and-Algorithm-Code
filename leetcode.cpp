#include <iostream>
using namespace std;

bool subsequence(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    int i = 0, j = 0;
    while (i >= 0 && i < n1 && j >= 0 && j < n2)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    if (j >= n2)
    {
        return true;
    }
    return false;
}

int main()
{

    string s1 = "abc";
    string s2 = "ad";
    bool res = false;

       for (int i = 0; i < s1.length(); i++)
    {
        /* code */
        if (s1[i] == 'z')
        {
            s1[i] = 'a';
        }
        else
        {
            s1[i]++;
        }

        if (subsequence(s1, s2))
        {
            res = true;
            break;
        }
    }

    cout << res;

    return 0;
}