class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        vector<int> dp(amount + 1, 2147483646);
        // for (int i = 0; i < coins.size() + 1; ++i) dp[i][0] = 0;
        dp[0] = 0;
        for (int i = 1; i < coins.size() + 1; ++i) {
            int c = coins[i - 1];
            for (int j = c; j < amount + 1; ++j) {
                if (j >= c && dp[j - c] != 2147483646) {
                    dp[j] = min(dp[j], dp[j - c] + 1);
                }
            }
            // for (auto& d : dp[i]) std::cout << d << ' ';
            // std::cout << '\n';
        }
        
        return dp[amount] == 2147483646 ? -1 : dp[amount];
    }
};
