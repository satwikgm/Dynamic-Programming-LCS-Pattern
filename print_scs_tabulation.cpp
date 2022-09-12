#include <bits/stdc++.h>
using namespace std;

// S1 = AGGTAB
// S2 = GXTXAYB
// SCS = AGGXTXAYB

string printSCS(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) // n==0
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) // m==0
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

    string ans = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s1[i - 1];
                i--;
            }
            else
            {
                ans += s2[j - 1];
                j--;
            }
        }
    }
    while (i > 0)
    {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += s2[j - 1];
        j--;
    }
    return ans;
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    // string s1 = "abac";
    // string s2 = "cab";
    int m = s1.size();
    int n = s2.size();
    string scs = printSCS(s1, s2, m, n);
    reverse(scs.begin(), scs.end());
    cout << "SCS : " << scs << endl;
    return 0;
}