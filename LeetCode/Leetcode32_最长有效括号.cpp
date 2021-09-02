class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
    
    int longestValidParentheses1(string s) {
        int len = s.length(), result = 0;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') dp[i][i]--;
            else if (s[i] == ')') dp[i][i]++;
        }
        
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (dp[i][j - 1] > 0) {
                    dp[i][j] = 2147483647;
                    break;
                }
                if (s[j] == '(') dp[i][j] = dp[i][j - 1] - 1;
                else dp[i][j] = dp[i][j - 1] + 1;
                if (!dp[i][j]) result = max(result, j - i + 1);
            }
        }
        
        // for (int i = 0; i < len; ++i) {
        //     for (int j = 0; j < len; ++j) {
        //         if (!dp[i][j]) result = max(result, j - i + 1);
        //     }
        // }
        
        return result;
    }
};
