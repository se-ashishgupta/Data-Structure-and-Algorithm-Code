#include <iostream>
#include <vector>
using namespace std;
int LongestSubstr(string &str) // TC:O(n)
{
    int size = str.length(), res = 0;
    int i = 0;
    vector<int> prev(256, -1);
    for (int j = 0; j < size; j++)
    {
        i = max(i, prev[str[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[str[j]] = j;
    }
    return res;
}
bool areDistinct(string str, int i, int j)
{

    vector<bool> visited(256);
    for (int k = i; k <= j; k++)
    {
        if (visited[str[j]] == true)
            return false;
        visited[str[k]] == true;
    }
    return true;
}
int LongestSubstrNaive1(string &str) // TC:O(n*n*n)
{
    int size = str.length(), res = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (areDistinct(str, i, j))
            {
                res = max(res, j - i + 1);
            }
        }
    }
}
int LongestSubstrNaive2(string &str) // TC:O(n*n)
{
    int size = str.length(), res = 0;

    for (int i = 0; i < size; i++)
    {
        vector<bool> v(256);
        for (int j = i; j < size; j++)
        {
            if (v[str[i]] == true)
                break;
            else
            {
                res = max(res, j - i + 1);
                v[str[i]] = true;
            }
        }
    }
    return res;
}
int main()
{
    string str = "abac";
    cout << LongestSubstrNaive1(str);
    return 0;
}