#include <bits/stdc++.h>
using namespace std;

// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.
// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s

// S1 = AGGTAB
// S2 = GXTXAYB
// SCS = AGGXTXAYB

int lcs(string s1, string s2, int m, int n)
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
    return dp[m][n];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.size();
    int n = s2.size();
    cout << "Length of lcs : " << lcs(s1, s2, m, n) << endl;
    cout << "=> Length of Shortest common supersequence = m+n-lcs = " << m + n - lcs(s1, s2, m, n) << endl;
    return 0;
}