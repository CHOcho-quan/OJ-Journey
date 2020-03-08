#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool isMatch(string s, string p) 
{
    //TLE
    if (p == s) return true;
    if (p.length() == 0) return false;
    if (s.length() == 0 && p[0] == '*') return isMatch(s, p.substr(1));
    else return false;

    if (p[0] == '?') return isMatch(s.substr(1), p.substr(1));
    if (p[0] == '*') return isMatch(s, p.substr(1)) || isMatch(s.substr(1), p);
    if (p[0] == s[0]) return isMatch(s.substr(1), p.substr(1));
    else return false;
}

bool isMatch_dp(string s, string p)
{
    int n_i = s.length()+1, n_j = p.length()+1;
    vector<vector<bool>> dp(n_i, vector<bool>(n_j, false));

    dp[0][0] = 1;
    for (int i = 0;i < n_i;i++)
    {
        for (int j = 0;j < n_j;j++)
        {
            if (i == 0 && j == 0) continue;
            if (j == 0 && i != 0) {dp[i][j] = 0;continue;}
            if (j != 0 && i == 0) {dp[i][j] = (dp[i][j-1] && p[j-1] == '*');continue;}

            if (p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
            if (p[j-1] == s[i-1]) dp[i][j] = dp[i-1][j-1];
            if (p[j-1] == '*') dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
        }
    }

    /*
    If not had the std::out noted
    Time Limited Error
    */
    for (int i = 0;i < dp.size();i++)
    {
        for (int j = 0;j < dp[i].size();j++) {cout << dp[i][j] << ' ';}
        cout << endl;
    }

    return dp[n_i-1][n_j-1];
}

int main()
{
    string s = "afdfd", p = "*";
    cout << isMatch_dp(s, p);
}