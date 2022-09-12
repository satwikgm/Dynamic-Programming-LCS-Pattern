// Given a string s, return the number of palindromic substrings in it.

// "abc" -> 3
// "aaa" -> 6

#include <iostream>
using namespace std;

int fun(string s, int i, int j)
{
    if(i>=j)
    {
        return 1;
    }
    if(s[i]==s[j])
    {
        return fun(s,i+1,j-1);
    }
    else
    {
        return 0;
    }
}

int countPalSubstrings(string s)
{
    int n = s.size();
    int dp[n + 1][n + 1];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            count += fun(s, i, j);
        }
    }
    return count;
}

int main()
{
    string s = "bvgag";
    cout<<"The no of palindromic substrings = "<<countPalSubstrings(s);
    return 0;
}