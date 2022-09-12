/*
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.
The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

str = "axxzxy"

a x x z x y
0 1 2 3 4 5
The longest subsequence is "xx".
It appears twice as explained below.
x x
1 2  <-- index of str

x x
2 4  <-- index of str

*/

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
            if (s1[i - 1] == s2[j - 1] && i != j) // Minor Change
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

int longestRepeatingSubsequence(string s, int n)
{
    return lcs(s, s, n, n);
}

int main()
{
    string s = "AABEBCDD";
    int n = s.size();
    cout << "Length of longest repeating subsequence : " << longestRepeatingSubsequence(s, n) << endl;
    return 0;
}