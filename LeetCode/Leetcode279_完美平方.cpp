class Solution {
public:
    int numSquares(int n) {
        int ch = sqrt(n) + 1;
        vector<int> rem;
        for (int i = 1; i < ch + 1; ++i) rem.push_back(ch * ch);
        vector<int> dp(n + 1, 100000000);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            int c = sqrt(i) + 1;
            for (int j = 1; j < c + 1; ++j) {
                if (j * j < i) {
                    dp[i] = min(dp[i - j * j] + 1, dp[i]);
                } else if (j * j == i) dp[i] = 1;
            }
        }
        // for (auto& d : dp) std::cout << d << ' ';
        return dp[n];
    }
};
