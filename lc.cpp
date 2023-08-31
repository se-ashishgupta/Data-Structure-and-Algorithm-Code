#include <iostream>
#include <vector>
using namespace std;

int PrefisSum(string &s, int n, int idx)
{
    if (idx >= n)
        return 0;
    int res = 0;
    if (s[idx] == 'L')
        return res = 1 - PrefisSum(s, n, idx + 1);

    if (s[idx] == 'L')
        return 1 + PrefisSum(s, n, idx + 1);
}

int main()
{
    vector<int> arr = {1, 8, 30, -5, 20, 7};

    return 0;
}
