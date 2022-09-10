#include <iostream>
using namespace std;

int longestCommonSubstring(string s1, string s2, int n1, int n2)
{
    int dp[n1 + 1][n2 + 1];
    int res = 0;
    for (int i = 0; i <= n2; i++) // n1==0
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n1; i++) // n2==0
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Contigous Chars match
                res = max(res, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return res;
}

int main()
{
    string s1 = "xyzabcd";
    string s2 = "abcdxyz";
    int n1 = 7;
    int n2 = 7;
    cout << "The length of longest common substring is : " << longestCommonSubstring(s1, s2, n1, n2) << endl;
    return 0;
}