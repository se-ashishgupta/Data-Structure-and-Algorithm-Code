#include <iostream>
#include <vector>
using namespace std;

int lcsMemo(string s1, string s2, int m, int n, vector<vector<int>> &memo)
{
    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }

    if (m == 0 || n == 0)
        memo[m][n] = 0;
    else
    {
        if (s1[m - 1] == s2[n - 1])
            memo[m][n] = 1 + lcsMemo(s1, s2, m - 1, n - 1, memo);
        else
            memo[m][n] = max(lcsMemo(s1, s2, m - 1, n, memo), lcsMemo(s1, s2, m, n - 1, memo));
    }

    return memo[m][n];
}
int lcsTab(string s1, string s2, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int lcs(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (s1[m - 1] == s2[n - 1])
        return 1 + lcs(s1, s2, m - 1, n - 1);
    else
        return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
}
int main()
{
    string s1 = "ASVD";
    string s2 = "ACV";

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    cout << lcs(s1, s2, m, n) << endl;
    cout << lcsMemo(s1, s2, m, n, memo) << endl;
    cout << lcsTab(s1, s2, m, n);
    return 0;
};