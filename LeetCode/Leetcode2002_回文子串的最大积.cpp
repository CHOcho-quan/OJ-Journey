class Solution {
public:
    bool palindrome(string t) {
        int l = 0, r = t.length() - 1;
        while (l <= r) {
            if (t[l++] != t[r--]) return false;
        }
        return true;
    }
    
    int maxProduct(string s) {
        int n = s.length(), m = 1 << n;
        vector<int> dp(m, 0);
        
        for (int i = 1; i < m; ++i) {
            string tmp = "";
            for (int j = 0; (1 << j) <= i; ++j) {
                if ((1 << j) & i) tmp += s[j];
            }
            if (palindrome(tmp)) dp[i] = tmp.length();
        }
        
        // for (auto& d : dp) cout << d << ' ';
        // cout << dp[128 + 10] << ' ' << dp[16 + 64 + 256] << ' ' << (dp[128 + 10] ^ dp[16 + 64 + 256]) << '\n';
        
        int result = 1;
        for (int i = 1; i < m; ++i) {
            if (!dp[i]) continue;
            for (int j = 1; j < m; ++j) {
                if ((i & j) == 0) {
                    result = max(result, dp[i] * dp[j]);
                }
            }
        }
        
        return result;
    }
};
