class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        for (int i = 2; i < n + 1; ++i) dp[i] = i;
        
        for (int i = 2; i < n + 1; ++i) {
            for (int j = i / 2; j > 0; --j) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i / j);
                }
            }
        }
        
        return dp[n];
    }
};
