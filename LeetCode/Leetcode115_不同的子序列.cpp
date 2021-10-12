class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        for (int i = 0; i < m + 1; ++i) dp[i][0] = 1;
        for (int i = 1; i < m + 1; ++i) {
            auto w1 = s[i - 1];
            for (int j = 1; j < n + 1; ++j) {
                auto w2 = t[j - 1];
                if (w1 == w2)
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[m][n];
    }
};
