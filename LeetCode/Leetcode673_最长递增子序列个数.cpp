class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), ln = 0, result = 0;
        vector<int> dp(n, 1), cnt(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[i] == dp[j] + 1) cnt[i] += cnt[j];
                }
            }
            ln = max(ln, dp[i]);
        }
        
        for (int i = 0; i < n; ++i) if (ln == dp[i]) result += cnt[i];
        return result;
    }
};
