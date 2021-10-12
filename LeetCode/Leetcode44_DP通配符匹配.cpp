class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i] || dp[0][i - 1];
        }
        
        for (int i = 1; i <= m; ++i) {
            auto w1 = s[i - 1];
            for (int j = 1; j <= n; ++j) {
                auto w2 = p[j - 1];
                if (w1 == w2) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
                } else if (w2 == '?') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
                } else if (w2 == '*') {
                    // w2 matches nothing
                    dp[i][j] = dp[i][j - 1] || dp[i][j];
                    // w2 matches something
                    dp[i][j] = dp[i - 1][j] || dp[i][j];
                }
            }
        }
        
        // for (int i = 0; i <= m; ++i) {
        //     for (int j = 0; j <= n; ++j) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        
        return dp[m][n];
    }
};
