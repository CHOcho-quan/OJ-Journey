class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                dp[i] = max(dp[i], max(dp[i - j], i - j) * max(dp[j], j));
            }
        }
        
        return dp[n];
    }
};
