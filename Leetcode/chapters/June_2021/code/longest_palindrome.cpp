#include <string>
#include <vector>
#include <iostream>

using namespace std;
string longestPalindrome(string s)
{

    // each cell indicates whether s[i,j] is a palindrome
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // cell[i][j] is the substring with length 1, it is always true
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    int i = 0, j = 0;

    for (int end = 1; end < n; end++)
    {
        for (int start = end - 1; start >= 0; start--)
        {

            // need both s[i]==s[j] and s[i+1][j-1]==true, or there is only
            // one char in between
            if (s[start] == s[end] && (dp[start + 1][end - 1] == 1 || end - start < 3))
            {
                dp[start][end] = 1;
                if (j - i < end - start)
                {
                    j = end;
                    i = start;
                }
            }
        }
    }

    return s.substr(i, j - i + 1);
}

int main()
{
    string k = "aabbaab";
    cout << longestPalindrome(k);
}