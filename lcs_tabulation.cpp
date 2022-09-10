#include <iostream>
using namespace std;

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
    string s1 = "abcde";
    string s2 = "ace";
    int m = 5;
    int n = 3;
    cout << "Length of lcs : " << lcs(s1, s2, m, n);
    return 0;
}