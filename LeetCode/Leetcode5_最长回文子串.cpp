class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int result = 1, n = s.length();
        string re = ""; re += s[0];
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if (i + 1 < n) {
                dp[i][i + 1] = s[i] == s[i + 1];
                if (dp[i][i + 1]) {
                    result = 2;
                    re = s.substr(i, 2);
                }
            }
        }
        
        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j + i - 1 >= n) continue;
                dp[j][j + i - 1] = dp[j + 1][j + i - 2] && (s[j] == s[j + i - 1]);
                if (dp[j][j + i - 1] && i > result) {
                    result = i;
                    re = s.substr(j, i);
                }
            }
        }
        
        return re;
    }
};
