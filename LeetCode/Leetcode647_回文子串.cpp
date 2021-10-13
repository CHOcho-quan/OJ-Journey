class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            ++res;
        }
        if (n == 1) return res;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + j >= n) break;
                if (s[j] == s[i + j]) {
                    if (i == 1) {
                        dp[j][i + j] = true;
                        ++res;
                        continue;
                    }
                    dp[j][i + j] = dp[j + 1][i + j - 1];
                    if (dp[j][i + j]) ++res;
                }
            }
            // cout << res <<'\n';
        }
        
        return res;
    }
};
