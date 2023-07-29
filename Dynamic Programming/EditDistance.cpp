#include <iostream>
#include <vector>
using namespace std;

int editDistance(string s1, string s2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    if (s1[m - 1] == s2[n - 1])
    {
        return editDistance(s1, s2, m - 1, n - 1);
    }
    else
    {
        return 1 + min((editDistance(s1, s2, m, n - 1), editDistance(s1, s2, m - 1, n)), editDistance(s1, s2, m - 1, n - 1));
    }
}
int editDistanceTab(string s1, string s2, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min((dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}
int main()
{
    string s1 = "CAT";
    string s2 = "CUTA";
    int m = s1.size();
    int n = s2.size();

    cout << editDistanceTab(s1, s2, m, n);
    return 0;
}
